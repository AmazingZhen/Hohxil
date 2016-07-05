#include "GrassFactory.h"
#include "Grass.h"
#include "GrassAggregation.h"
#include "FoodChain.h"

void GrassFactory::createCreature()
{
	//初始添加草
	GrassAggregation* gra = GrassAggregation::getInstance();
	LargeMap* largeMap = (LargeMap*)LargeMap::getInstance();
	int mapSize = largeMap->getMapSize();
	for (int i = 0; i < mapSize; i++)
	{
		// Add to model
		Creature* grass = Grass::create();
		gra->addMember(grass);
		// Add to view
		auto gameMap = largeMap->getGameMapSpriteById(i)->getGameMap();
		gameMap->addChild(grass, 1);

		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		grass->setPosition(Vec2(origin.x + randomNum(0.0, visibleSize.width),
			origin.y + randomNum(0.0, visibleSize.height)));
	}
	//添加到食物链
	FoodChain* foodChain = FoodChain::getInstance();
	foodChain->addAggregation(gra);
}
