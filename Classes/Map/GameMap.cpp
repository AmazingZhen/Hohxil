#include "GameMap.h"
#include "LargeMap.h"

USING_NS_CC;

Scene* GameMap::createScene() {
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = GameMap::create();

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
	Director::getInstance()->replaceScene(TransitionFade::create(0.5f, LargeMap::getInstance()));
}


void GameMap::createMenu() {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto closeItem = MenuItemImage::create(
		"CloseNormal.png",
		"CloseSelected.png",
		CC_CALLBACK_1(GameMap::menuCloseCallback, this));

	closeItem->setPosition(Vec2(origin.x + visibleSize.width - closeItem->getContentSize().width / 2,
		origin.y + closeItem->getContentSize().height / 2));

	// create menu, it's an autorelease object
	auto menu = Menu::create(closeItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);
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
