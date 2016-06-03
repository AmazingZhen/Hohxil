#include "LargeMap.h"
#include "GameSchedule.h"
#include "GamePause.h"

Scene* LargeMap::largeMap = nullptr;
cocos2d::Vector<GameMapSprite*> LargeMap::maps = cocos2d::Vector<GameMapSprite*>();

USING_NS_CC;

int randomNum(int min, int max) {
	assert(max >= min);

	return rand() % (max - min + 1) + min;
}

double randomNum(double min, double max) {
	assert(max >= min);

	return ((double)rand() / (double)RAND_MAX) * (max - min) + min;
}

Scene* LargeMap::getInstance() {
	if (largeMap == nullptr) {
		largeMap = createScene();
	}
	return largeMap;
}

GameMapSprite* LargeMap::getGameMapSpriteById(int mapId) {
	return maps.at(mapId);
}

// on "init" you need to initialize your instance
bool LargeMap::init()
{
	//////////////////////////////
	// 1. super init first
	if (!Layer::init())
	{
		return false;
	}

	/////////////////////////////
	// 2. add your codes below..
	createMaps(MAP_NUM);


	/////////////////////////////
	// 3. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.
	// add a "close" icon to exit the progress. it's an autorelease object
	createMenu();

	// this->scheduleUpdate();

	GameSchedule::getInstance()->start();

	return true;
}

Scene* LargeMap::createScene() {
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LargeMap::create();
	layer->setTag(1);

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

void LargeMap::menuCloseCallback(Ref* pSender) {
	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void LargeMap::menuPauseCallback(Ref* pSender) {
	GameSchedule::getInstance()->pause();

	// size value
	Size visibleSize = Director::getInstance()->getVisibleSize();
	RenderTexture *renderTexture = RenderTexture::create(visibleSize.width, visibleSize.height);

	// save the renderTexture as background
	renderTexture->begin();
	getParent()->visit();
	renderTexture->end();

	// create a gray scene meaning a pause
	Director::getInstance()->pushScene(GamePause::scene(renderTexture));
}

void LargeMap::menuIntervalCallback(Ref* pSender) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	updateMenuIntervalButton();
}

void LargeMap::updateMenuIntervalButton() {
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

void LargeMap::createMenu() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"UI/CloseNormal.png",
		"UI/CloseSelected.png",
		CC_CALLBACK_1(LargeMap::menuCloseCallback, this));
	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));
	closeItem->setName("Close Button");

	// Pause Button
	auto pauseItem = MenuItemImage::create(
		"UI/PauseNormal.png",
		"UI/PauseSelected.png",
		CC_CALLBACK_1(LargeMap::menuPauseCallback, this));
	pauseItem->setPosition(Vec2(origin.x + visibleSize.width - pauseItem->getContentSize().width / 2,
		origin.y + visibleSize.height - pauseItem->getContentSize().height / 2));
	pauseItem->setName("Pause Button");

	// Interval Button
	auto intervalItem = MenuItemImage::create(
		"UI/SpeedOneNormal.png",
		"UI/SpeedOneSelected.png",
		CC_CALLBACK_1(LargeMap::menuIntervalCallback, this));
	intervalItem->setPosition(Vec2(origin.x + visibleSize.width - intervalItem->getContentSize().width / 2 - pauseItem->getContentSize().width,
		origin.y + visibleSize.height - intervalItem->getContentSize().height / 2));
	intervalItem->setName("Interval Button");

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, pauseItem, intervalItem, NULL);
	menu->setName("Menu");
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 8);
}

// Need for improvement later.
GameMapSprite* LargeMap::createMap() {
	auto gameMapSprite = GameMapSprite::create("map/game_map.png");

	return gameMapSprite;
}

void LargeMap::createMaps(int mapNum) {
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

	// Adding maps.
	// Randomly.

	srand(time(0));

	for (int i = 0; i < mapNum; i++) {
		auto newMap = createMap();
		Size mapSize = newMap->getContentSize();

		float xPos = randomNum(mapSize.width / 2, visibleSize.width - mapSize.width / 2);
		float yPos = randomNum(mapSize.height / 2, visibleSize.height - mapSize.height / 2);
		newMap->setPosition(Vec2(xPos, yPos));

		// Check if overlap other existing maps.
		bool containFlag = false;
		for (int j = 0; j < maps.size(); j++) {
			if (maps.at(j)->getBoundingBox().intersectsRect(newMap->getBoundingBox())) {
				containFlag = true;
				break;
			}
		}

		while (containFlag) {
			float xPos = randomNum(mapSize.width / 2, visibleSize.width - mapSize.width / 2);
			float yPos = randomNum(mapSize.height / 2, visibleSize.height - mapSize.height / 2);
			newMap->setPosition(Vec2(xPos, yPos));

			containFlag = false;
			for (int j = 0; j < maps.size(); j++) {
				if (maps.at(j)->getBoundingBox().intersectsRect(newMap->getBoundingBox())) {
					containFlag = true;
					break;
				}
			}
		}

		maps.pushBack(newMap);
		this->addChild(newMap, 1);
	}
}
