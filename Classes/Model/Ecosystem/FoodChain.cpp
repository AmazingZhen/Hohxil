#include "FoodChain.h"
#include "LargeMap.h"
#include "GameMapSprite.h"
#include "CreatureFactory.h"
#include "GrassFactory.h"
#include "SheepFactory.h"
#include "WolfFactory.h"
#include "GrassAggregation.h"
#include "SheepAggregation.h"
#include "WolfAggregation.h"

using std::vector;

#define REFRESH_INTERVAL 300

FoodChain::FoodChain()
{
    largeMap = (LargeMap*)LargeMap::getInstance();
	grassLand = (GameMap*)largeMap->getGameMapSpriteById(1)->getGameMap();
}

FoodChain::~FoodChain()
{
	eraseAllAggregations();
}

// 单实例
FoodChain* FoodChain::instance = NULL;

// 单实例模式
FoodChain* FoodChain::getInstance()
{
	if (instance == NULL)
	{
		instance = new FoodChain();
	}
	return instance;
}

//初始化一个食物链：即初始化添加相应的生物
void FoodChain::init()
{
    //初始添加草
	CreatureFactory* grf = new GrassFactory();
	grf->createCreature();

	//初始添加羊
	CreatureFactory* srf = new SheepFactory();
	srf->createCreature();

	//初始添加狼
	CreatureFactory* wrf = new WolfFactory();
	wrf->createCreature();
}

//接下来的三个函数是关于时间操作的函数
float FoodChain::getRefreshInterval()
{
	return REFRESH_INTERVAL;
}

float FoodChain::getCurrentRefreshInterval()
{
	return currentRefreshInterval;
}

void FoodChain::addCurrentRefreshInterval(float time)
{
	currentRefreshInterval = currentRefreshInterval + time;
}

// 添加集群
void FoodChain::addAggregation(CreatureAggregation* creatureAggregation)
{
	aggregationList.push_back(creatureAggregation);

	/* 更新totalMassCanBeUsed */

}

// 删除特定集群
bool FoodChain::eraseAggregation(CreatureAggregation* creatureAggregation)
{
	vector<CreatureAggregation*>::iterator aggregationIter = aggregationList.begin();
	vector<float>::iterator totalMassIter = totalMassCanBeUsed.begin();
	for ( ; aggregationIter != aggregationList.end(); aggregationIter++, totalMassIter++)
	{
		if ((*aggregationIter)->isEqual(creatureAggregation))
		{
			// 删除集群
			aggregationList.erase(aggregationIter);
			// 删除对应的可消耗能量
			totalMassCanBeUsed.erase(totalMassIter);
			return true;
		}
	}
	return false;
}

// 删除给定物种的集群
bool FoodChain::eraseAggregation(const CreatureSpecies& species)
{
	vector<CreatureAggregation*>::iterator aggregationIter = aggregationList.begin();
	vector<float>::iterator totalMassIter = totalMassCanBeUsed.begin();
	for (; aggregationIter != aggregationList.end(); aggregationIter++, totalMassIter++)
	{
		if ((*aggregationIter)->getSpecies() == species)
		{
			// 删除集群
			aggregationList.erase(aggregationIter);
			// 删除对应的可消耗能量
			totalMassCanBeUsed.erase(totalMassIter);
			return true;
		}
	}
	return false;
}

// 删除所有集群
void FoodChain::eraseAllAggregations()
{
	// 删除集群
	aggregationList.clear();
	// 删除对应的可消耗能量
	totalMassCanBeUsed.clear();
}

// 获取给定物种的集群
CreatureAggregation* FoodChain::getAggregation(const CreatureSpecies& species)
{
	for (vector<CreatureAggregation*>::iterator i = aggregationList.begin(); i != aggregationList.end(); i++)
	{
		if ((*i)->getSpecies() == species)
		{
			return (*i);
		}
	}
	return NULL;
}

// 获取集群数目
int FoodChain::getAggregationCount() const
{
	return aggregationList.size();
}

// 获取所有集群
const vector<CreatureAggregation*> FoodChain::getAllAggregations() const
{
	return aggregationList;
}

void FoodChain::clearing()
{
	for (unsigned i = 0; i < aggregationList.size(); i++)
	{
		if (aggregationList[i]->getType() == CreatureType::Producer)
		{
			//aggregationList[i]->energyCreatedPerUnitTime();
			aggregationList[i]->massCanBeConsumed();
		}
		else if (aggregationList[i]->getType() == CreatureType::Consumer)
		{
			//aggregationList[i]->energyConsumedPerUnitTime();
			aggregationList[i]->massCanBeConsumed();
		}
		aggregationList[i]->clearingBirthAndUpdate();
		aggregationList[i]->clearingDeathAndUpdate();
		aggregationList[i]->influenceToLastGrade();
	}
}

//不同动作的影响
void FoodChain::sheepEatGrassInfluence()
{

}

void FoodChain::eraseDiedSheep()
{

}

void FoodChain::wolfEatSheepInfluence(float numRequired)
{

}

float FoodChain::energyConvertion(float orignalEnergy)
{
	return 0;
}
