#include "WolfFactory.h"
#include "Model\Creatures\Wolf.h"
#include "Model\CreatureAggregations\WolfAggregation.h"
#include "Model\Ecosystem\FoodChain.h"

void WolfFactory::createCreature()
{
	WolfAggregation* woa = WolfAggregation::getInstance();
	LargeMap* largeMap = (LargeMap*)LargeMap::getInstance();

	auto listener = createListener();

	for (int i = 0; i < 2; i++)
	{
		//��ӵ�Model
		Creature* wolf = Wolf::create();
		woa->addMember(wolf);

		//��ӵ�Map��ʾ
		auto gameMap = largeMap->getGameMapSpriteById(id)->getGameMap();
		gameMap->addChild(wolf, 1);
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		wolf->setPosition(Vec2(origin.x + randomNum(0.0, visibleSize.width),
			origin.y + randomNum(0.0, visibleSize.height)));

		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener->clone(), wolf);
	}

	//��ӵ�ʳ����
	FoodChain::getInstance()->addAggregation(woa);
}

void WolfFactory::createWolf(GameMap* gameMap, Vec2 &pos) {
	WolfAggregation* woa = WolfAggregation::getInstance();

	auto listener = createListener();
	Creature* wolf = Wolf::create();
	woa->addMember(wolf);
	gameMap->addChild(wolf, 1);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	wolf->setPosition(pos);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener->clone(), wolf);
}
