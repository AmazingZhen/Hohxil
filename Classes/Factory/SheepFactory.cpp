#include "SheepFactory.h"
#include "Model\Creatures\Sheep.h"
#include "Model\CreatureAggregations\SheepAggregation.h"
#include "Model\Ecosystem\FoodChain.h"


void SheepFactory::createCreature()
{
    SheepAggregation* sha = SheepAggregation::getInstance();
	LargeMap* largeMap = (LargeMap*)LargeMap::getInstance();

	auto listener = createListener();

	//��ʼ����
	int sheepNum = 20;
	for (int i = 0; i < sheepNum; i++)
	{
		//��ӵ�Model
		Creature* sheep = Sheep::create();
		sha->addMember(sheep);

		//��ӵ�Map��ʾ
		auto gameMap = largeMap->getGameMapSpriteById(id)->getGameMap();
		gameMap->addChild(sheep, 1);
		Size visibleSize = Director::getInstance()->getVisibleSize();
		Vec2 origin = Director::getInstance()->getVisibleOrigin();
		sheep->setPosition(Vec2(origin.x + randomNum(0.0, visibleSize.width),
			origin.y + randomNum(0.0, visibleSize.height)));

		// Add a listener to it.
		Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener->clone(), sheep);
	}

	//��ӵ�ʳ����
	FoodChain::getInstance()->addAggregation(sha);
}

void SheepFactory::createSheep(GameMap* gameMap, Vec2 &pos) {
	SheepAggregation* sha = SheepAggregation::getInstance();

	auto listener = createListener();
	Creature* sheep = Sheep::create();
	sha->addMember(sheep);
	gameMap->addChild(sheep, 1);
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();
	sheep->setPosition(pos);
	Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener->clone(), sheep);
}
