#include "SheepFactory.h"
#include "Sheep.h"
#include "SheepAggregation.h"
#include "FoodChain.h"


void SheepFactory::createCreature()
{
    SheepAggregation* sha = SheepAggregation::getInstance();
	LargeMap* largeMap = (LargeMap*)LargeMap::getInstance();

	auto listener = createListener();

	auto gameMap = largeMap->getGameMapSpriteById(id)->getGameMap();

	//初始化羊
	int sheepNum = 20;
	for (int i = 0; i < sheepNum; i++)
	{
		//添加到Model
		Creature* sheep = Sheep::create();
		sha->addMember(sheep);

		//添加到Map显示
		auto gameMap = largeMap->getGameMapSpriteById(id)->getGameMap();
		gameMap->addChild(sheep, 1);
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		sheep->setPosition(Vec2(origin.x + randomNum(0.0, visibleSize.width),
			origin.y + randomNum(0.0, visibleSize.height)));

		// Add a listener to it.
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener->clone(), sheep);
	}

	//添加到食物链
	FoodChain::getInstance()->addAggregation(sha);
}

/**
* added by xuyongzhe
*/
void SheepFactory::createSheep(Scene* gameScene, Vec2 pos) {

	SheepAggregation* sha = SheepAggregation::getInstance();

	auto listener = createListener();
	Creature* sheep = Sheep::create();
	sha->addMember(sheep);
	gameScene->addChild(sheep, 1);

	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	sheep->setPosition(pos);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener->clone(), sheep);
}
