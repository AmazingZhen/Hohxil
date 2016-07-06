#include "GameSuccess.h"
#include "GameSchedule.h"
#include "LargeMap.h"

bool GameSuccess::init() {
	if (!Layer::init()) {
		return false;
	}
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	Sprite* background = Sprite::create("map/success_or_fail.jpg");
	background->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(background);

	auto label = Label::createWithSystemFont("Winner!", "Microsoft JhengHei UI", 30);
	label->setPosition(Vec2(origin.x + visibleSize.width / 2, origin.y + visibleSize.height - label->getContentSize().height - 30));
	this->addChild(label, 1);
	auto endItem = MenuItemLabel::create(Label::createWithSystemFont("End", "Microsoft JhengHei UI", label->getContentSize().height),
		CC_CALLBACK_1(GameSuccess::menuEndCallback, this));
	//auto restartItem = MenuItemLabel::create(Label::createWithSystemFont("Restart", "Microsoft JhengHei UI", label->getContentSize().height),
	//	CC_CALLBACK_1(GameSuccess::menuRestartCallback, this));
	auto menu = Menu::create(endItem, NULL);
	menu->setPosition(Director::getInstance()->getVisibleSize().width / 2, Director::getInstance()->getVisibleSize().height / 2);
	menu->alignItemsVerticallyWithPadding(label->getContentSize().height / 2);
	this->addChild(menu, 1);
	return true;
}

Scene* GameSuccess::createScene() {
	auto scene = Scene::create();
	auto layer = GameSuccess::create();
	scene->addChild(layer);
	return scene;
}

// 重新开始  
void GameSuccess::menuRestartCallback(Ref* pSender) {

}
// 结束游戏
void GameSuccess::menuEndCallback(Ref* pSender) {
	GameSchedule::getInstance()->end();
	Director::getInstance()->end();
}
