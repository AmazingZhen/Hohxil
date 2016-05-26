#include "LargeMap.h"
#include "GameSchedule.h"

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
	// 2. add a menu item with "X" image, which is clicked to quit the program
	//    you may modify it.

	// add a "close" icon to exit the progress. it's an autorelease object
	createMenu();

	/////////////////////////////
	// 3. add your codes below...

	createMaps(MAP_NUM);

	// this->scheduleUpdate();

	GameSchedule::getInstance()->start();

	return true;
}

Scene* LargeMap::createScene() {
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = LargeMap::create();

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

void LargeMap::createMenu() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(LargeMap::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
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
