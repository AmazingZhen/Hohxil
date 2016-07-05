#include "DragLayer.h"
#include <math.h>

void DragLayer::initLayer() {
	this->setAnchorPoint(Vec2::ZERO);
	this->padding = 10;
	this->width = padding;
	this->height = 2 * padding;
	this->background = Sprite::create("drag_menu_bg.jpg");
	this->background->setAnchorPoint(Vec2::ZERO);
	this->background->setPosition(Vec2::ZERO);
	this->addChild(background);
	scaleBackground();
}

void DragLayer::scaleBackground() {
	float bgWidth = background->getContentSize().width,
		bgHeight = background->getContentSize().height;
	float scaleX = this->width / bgWidth,
		scaleY = this->height / bgHeight;
	background->setScaleX(scaleX);
	background->setScaleY(scaleY);
}

// bugs
//DragLayer* DragLayer::create(DragItemImage* item1, ...) {
//	DragLayer* dragPanel = new (std::nothrow) DragLayer();
//	if (dragPanel) {
//		dragPanel->initMenu();
//		va_list argptr;
//		va_start(argptr, item1);
//		if (item1) {
//			dragPanel->addDragItem(item1);
//			DragItemImage *i = va_arg(argptr, DragItemImage*);
//			while (i) {
//				dragPanel->addDragItem(i);
//				i = va_arg(argptr, DragItemImage*);
//			}
//		}
//		va_end(argptr);
//		return dragPanel;
//	}
//	CC_SAFE_DELETE(dragPanel);
//	return nullptr;
//}


DragLayer* DragLayer::create() {
	DragLayer* dragPanel = new (std::nothrow) DragLayer();
	if (dragPanel) {
		dragPanel->initLayer();
		return dragPanel;
	}
	CC_SAFE_DELETE(dragPanel);
	return nullptr;
}

float DragLayer::getWidth() {
	return this->width;
}

float DragLayer::getHeight() {
	return this->height;
}

Sprite* DragLayer::getBackground() {
	return this->background;
}


void DragLayer::addDragItem(DragItemImage* dragItem) {
	dragItems.pushBack(dragItem);
	this->addChild(dragItem, 1);
	Size s = dragItem->getContentSize();
	dragItem->setPosition(Vec2(width + s.width / 2, padding + s.height / 2));
	dragItem->initOriginalPoint(Point(width + s.width / 2, padding + s.height / 2));
	this->width += dragItem->getContentSize().width + padding;
	this->height = max(this->height, dragItem->getContentSize().height + 2 * padding);
	this->setContentSize(Size(width, height));
	scaleBackground();
}


