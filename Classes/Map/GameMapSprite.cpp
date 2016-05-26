#include "GameMapSprite.h"
#include "LargeMap.h"
#include "GameMap.h"
#include "HelloWorldScene.h"

USING_NS_CC;

GameMapSprite* GameMapSprite::create(const std::string& filename) {
	GameMapSprite *gameMapSprite = new (std::nothrow) GameMapSprite();
	if (gameMapSprite && gameMapSprite->initWithFile(filename))
	{
		gameMapSprite->initGameMap();
		gameMapSprite->addCallbackFunc();
		gameMapSprite->autorelease();
		return gameMapSprite;
	}
	CC_SAFE_DELETE(gameMapSprite);
	return nullptr;
}

void GameMapSprite::addCallbackFunc() {
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [this](Touch* touch, Event* event) {
		Point locationInNode = this->convertToNodeSpace(touch->getLocation());

		Size s = this->getContentSize();
		Rect rect = Rect(0, 0, s.width, s.height);

		if (rect.containsPoint(locationInNode)) {
			return true;
		}

		return false;
	};

	listener->onTouchEnded = [this](Touch* touch, Event* event) {
		this->updateGameMap();

		Director::getInstance()->replaceScene(TransitionFade::create(0.5f, this->getGameMap()));
	};

	this->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, this);
}

void GameMapSprite::initGameMap() {
	gameMap = GameMap::createScene();

	// Important! To avoid released by cocos2d itself.
	gameMap->retain();
}

void GameMapSprite::updateGameMap() {
	
}