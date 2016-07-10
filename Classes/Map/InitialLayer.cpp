#include "InitialLayer.h"
#include "Map\LargeMap.h"
USING_NS_CC;

static bool isOpenSetting = false;

Scene* InitialLayer::createScene()
{
	// 'scene' is an autorelease object
	auto scene = Scene::create();

	// 'layer' is an autorelease object
	auto layer = InitialLayer::create();

	// add layer as a child to scene
	scene->addChild(layer);

	// return the scene
	return scene;
}

// on "init" you need to initialize your instance
bool InitialLayer::init()
{
	if (!Layer::init())
	{
		return false;
	}

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	//Menu Buttons
	auto exitItem = MenuItemImage::create("UI/InitialLayer/exit_normal.jpg", "UI/InitialLayer/exit_selected.jpg", CC_CALLBACK_1(InitialLayer::menuExitCallback, this));
	exitItem->setAnchorPoint(Point(0.5, 0.5));
	exitItem->setScale((double)(visibleSize.width / 12.0) /(exitItem->getContentSize().width));
	exitItem->setPosition(Vec2(visibleSize.width / 4, visibleSize.height / 4));
	auto nextItem = MenuItemImage::create("UI/InitialLayer/next_normal.jpg", "UI/InitialLayer/next_selected.jpg", CC_CALLBACK_1(InitialLayer::menuStartCallBack, this));
	nextItem->setAnchorPoint(Point(0.5, 0.5));
	nextItem->setScale((double)(visibleSize.width / 12.0) / (exitItem->getContentSize().width));
	nextItem->setPosition(Vec2(visibleSize.width * 3 / 4, visibleSize.height / 4));
	auto settingItem = MenuItemImage::create("UI/InitialLayer/setting_normal.jpg", "UI/InitialLayer/setting_selected.jpg", CC_CALLBACK_1(InitialLayer::menuSettingCallBack, this));
	settingItem->setAnchorPoint(Point(0.5, 0.5));
	settingItem->setScale((double)(visibleSize.width / 12.0) / (exitItem->getContentSize().width));
	settingItem->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 4));
	auto menu = Menu::create(exitItem, nextItem, settingItem, NULL);
	menu->setPosition(Vec2::ZERO);
	this->addChild(menu, 1);

	// create title
	auto label = Label::createWithTTF("Hohxil", "fonts/DK Weltschmerz_0.otf", 76);
	label->setColor(Color3B(255,48,38));
	label->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 4 / 5));
	this->addChild(label, 1);

	// add Background Image"
	auto backgroundImg = Sprite::create("map/initial_background.jpg");
	backgroundImg->setPosition(Vec2(visibleSize.width / 2 + origin.x, visibleSize.height / 2 + origin.y));
	this->addChild(backgroundImg, 0);

	return true;
}


void InitialLayer::menuExitCallback(Ref* pSender)
{
#if (CC_TARGET_PLATFORM == CC_PLATFORM_WP8) || (CC_TARGET_PLATFORM == CC_PLATFORM_WINRT)
	MessageBox("You pressed the close button. Windows Store Apps do not implement a close button.", "Alert");
	return;
#endif

	Director::getInstance()->end();

#if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
	exit(0);
#endif
}

void InitialLayer::menuStartCallBack(Ref* pSender) {
	//this->removeAllChildren();

	auto scene = LargeMap::getInstance();

	scene->retain();

	Director::getInstance()->pushScene(scene);
}


void InitialLayer::menuSettingCallBack(Ref* pSender) {
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	if (!isOpenSetting) {
		helpScene = Sprite::create("UI/InitialLayer/help.png");
		helpScene->setName("HelpScene");
		helpScene->setPosition(Vec2(visibleSize.width / 2 + origin.x, -visibleSize.height));
		this->addChild(helpScene, 10);

		auto act = MoveTo::create(1.0f, Vec2(visibleSize.width / 2 + origin.x, visibleSize.height * 3 / 5 + origin.y));
		helpScene->runAction(act);
		isOpenSetting = true;
	}
	else {
		removeChildByName("HelpScene");
		isOpenSetting = false;
	}
}

void InitialLayer::okCallBack(Ref* pSender) {
	helpScene->setVisible(false);
	okItem->setVisible(false);
}
