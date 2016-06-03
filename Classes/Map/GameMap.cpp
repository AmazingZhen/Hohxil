#include "GameMap.h"
#include "LargeMap.h"
#include "GameSchedule.h"
#include "GamePause.h"

USING_NS_CC;

Scene* GameMap::createScene() {
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameMap::create();
	layer->setTag(1);

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool GameMap::init() {
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	/////////////////////////////
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	createMenu();

	/////////////////////////////
	// 3. add your codes below...
	createMap();


	return true;
}

void GameMap::menuCloseCallback(Ref* pSender) {
	// update the speed button
	int speed = GameSchedule::getInstance()->getSpeed();
	MenuItemImage* intervalItem = (MenuItemImage*)LargeMap::getInstance()->getChildByTag(1)->getChildByName("Menu")->getChildByName("Interval Button");
	if (speed == 2) {
		intervalItem->setNormalImage(Sprite::create("UI/SpeedTwoNormal.png"));
		intervalItem->setSelectedImage(Sprite::create("UI/SpeedTwoSelected.png"));
	}
	else if (speed == 4) {
		intervalItem->setNormalImage(Sprite::create("UI/SpeedFourNormal.png"));
		intervalItem->setSelectedImage(Sprite::create("UI/SpeedFourSelected.png"));
	}
	else if (speed == 1) {
		intervalItem->setNormalImage(Sprite::create("UI/SpeedOneNormal.png"));
		intervalItem->setSelectedImage(Sprite::create("UI/SpeedOneSelected.png"));
	}
	// return largemap
	Director::getInstance()->replaceScene(TransitionFade::create(0.5f, LargeMap::getInstance()));
}

void GameMap::menuPauseCallback(Ref* pSender) {
	GameSchedule::getInstance()->pause();

	// size value
	Size visibleSize =Director::getInstance()->getVisibleSize();
	RenderTexture *renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);

	// save the renderTexture as background
	renderTexture->begin();
	getParent()->visit();
	renderTexture->end();

	// create a gray scene meaning a pause
	Director::getInstance()->pushScene(GamePause::scene(renderTexture));
}

void GameMap::menuIntervalCallback(Ref* pSender) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	int speed = GameSchedule::getInstance()->getSpeed();
	MenuItemImage* intervalItem = (MenuItemImage*)this->getChildByName("Menu")->getChildByName("Interval Button");
	if (speed == 1) {
		intervalItem->setNormalImage(Sprite::create("UI/SpeedTwoNormal.png"));
		intervalItem->setSelectedImage(Sprite::create("UI/SpeedTwoSelected.png"));
		GameSchedule::getInstance()->setSpeed(2);
	}
	else if (speed == 2) {
		intervalItem->setNormalImage(Sprite::create("UI/SpeedFourNormal.png"));
		intervalItem->setSelectedImage(Sprite::create("UI/SpeedFourSelected.png"));
		GameSchedule::getInstance()->setSpeed(4);
	}
	else if (speed == 4) {
		intervalItem->setNormalImage(Sprite::create("UI/SpeedOneNormal.png"));
		intervalItem->setSelectedImage(Sprite::create("UI/SpeedOneSelected.png"));
		GameSchedule::getInstance()->setSpeed(1);
	}
}

void GameMap::createMenu() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"UI/CloseNormal.png",
		"UI/CloseSelected.png",
		CC_CALLBACK_1(GameMap::menuCloseCallback, this));
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));
	closeItem->setName("Close Button");

	// pauseItem
	auto pauseItem = MenuItemImage::create(
		"UI/PauseNormal.png",
		"UI/PauseSelected.png",
		CC_CALLBACK_1(GameMap::menuPauseCallback, this));
	pauseItem->setPosition(Vec2(origin.x + visibleSize.width - pauseItem->getContentSize().width / 2,
		origin.y + visibleSize.height - pauseItem->getContentSize().height / 2));
	pauseItem->setName("Pause Button");

	// Interval Button
	auto intervalItem = MenuItemImage::create(
		"UI/SpeedOneNormal.png",
		"UI/SpeedOneSelected.png",
		CC_CALLBACK_1(GameMap::menuIntervalCallback, this));
	intervalItem->setPosition(Vec2(origin.x + visibleSize.width - intervalItem->getContentSize().width / 2 - pauseItem->getContentSize().width,
		origin.y + visibleSize.height - intervalItem->getContentSize().height / 2));
	intervalItem->setName("Interval Button");

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, pauseItem, intervalItem, NULL);
	menu->setName("Menu");
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 8);
}

void GameMap::createMap() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	// Adding background.

	auto background = Sprite::create("map/background.png");
	Texture2D::TexParams texParams = { GL_LINEAR, GL_LINEAR, GL_REPEAT, GL_REPEAT };
	background->getTexture()->setTexParameters(texParams);

	background->setTextureRect(Rect(0, 0, visibleSize.width, visibleSize.height));
	background->setPosition(origin);
	background->setAnchorPoint(Vec2(0, 0));

	this->addChild(background);
}
