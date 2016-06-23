#include "DragItemImage.h"
#include "DragLayer.h"
#include "Map\GameMap.h"
#include "Factory\SheepFactory.h"
#include "Factory\WolfFactory.h"

DragItemImage::DragItemImage(GameMap* gameMap, CreatureSpecies spec) {
	this->gameMap = gameMap;
	this->species = spec;
	this->isDragged = false;
	this->sum = 5;
}

DragItemImage* DragItemImage::create(const string& normalImage, const string& selectedImage, const string& disabledImage, GameMap* gameMap, CreatureSpecies spec) {
	DragItemImage *dragMenuItemImage = new (std::nothrow) DragItemImage(gameMap, spec);
	if (dragMenuItemImage && dragMenuItemImage->initWithNormalImage(normalImage, selectedImage, disabledImage, nullptr)) {
		dragMenuItemImage->initMouseLintener();
		dragMenuItemImage->retain();
		return dragMenuItemImage;
	}
	CC_SAFE_DELETE(dragMenuItemImage);
	return nullptr;
}

void DragItemImage::initOriginalPoint(Point &p) {
	this->originPos = p;
}

Point DragItemImage::getOriginalPoint() {
	return originPos;
}

void DragItemImage::initMouseLintener() {
	EventListenerTouchOneByOne* listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(DragItemImage::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(DragItemImage::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(DragItemImage::onTouchEnded, this);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

bool DragItemImage::onTouchBegan(Touch* touch, Event* event) {
	log("onTouchBegan");
	auto target = static_cast<DragItemImage*>(event->getCurrentTarget());
	Point locationInNode = target->convertToNodeSpace(touch->getLocation());
	Size s = target->getContentSize();
	Rect rect = Rect(0, 0, s.width, s.height);
	if (rect.containsPoint(locationInNode) && target->sum > 0) {
		target->isDragged = true;
		return true;
	}
	return false;
}

void DragItemImage::onTouchMoved(Touch* touch, Event* event) {
	//log("onTouchMoved");
	auto target = static_cast<DragItemImage*>(event->getCurrentTarget());
	if (isDragged == true) {
		Point locationInNode = getParent()->convertToNodeSpace(touch->getLocation());
		this->setPosition(locationInNode);
	}
}

void DragItemImage::onTouchEnded(Touch* touch, Event* event) {
	log("onTouchEnded");
	if (isDragged == true) {
		isDragged = false;
		auto parent = this->getParent();
		Point locationInNode = parent->convertToNodeSpace(touch->getLocation());
		//Size parentSize = parent->getContentSize();
		Size backgroundSize = ((DragLayer*)parent)->getBackground()->getBoundingBox().size;
		Size itemSize = this->getContentSize();
		//Rect rect = Rect(0-itemSize.width, 0-itemSize.height, 
		//	parentSize.width+itemSize.width, parentSize.height+itemSize.height);
		Rect rect = Rect(0-itemSize.width, 0-itemSize.height, 
			backgroundSize.width + itemSize.width, backgroundSize.height + itemSize.height);
		if (rect.containsPoint(locationInNode)) {
			this->setPosition(originPos);
		}
		else {
			this->setPosition(originPos);
			--sum;
			SheepFactory sheepFactory;
			WolfFactory wolfFactory;
			switch (species)
			{
			case Grass:
				break;
			case Sheep:
				sheepFactory.createSheep(this->gameMap, touch->getLocation());
				break;
			case Wolf:
				wolfFactory.createWolf(this->gameMap, touch->getLocation());
				break;
			default:
				break;
			}
			if (sum == 0) {
				this->setEnabled(false);
			}
		}
	}
}