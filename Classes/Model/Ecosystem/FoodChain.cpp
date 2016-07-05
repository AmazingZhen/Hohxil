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

// ��ʵ��
FoodChain* FoodChain::instance = NULL;

// ��ʵ��ģʽ
FoodChain* FoodChain::getInstance()
{
	if (instance == NULL)
	{
		instance = new FoodChain();
	}
	return instance;
}

//��ʼ��һ��ʳ����������ʼ�������Ӧ������
void FoodChain::init()
{
    //��ʼ��Ӳ�
	CreatureFactory* grf = new GrassFactory();
	grf->createCreature();

	//��ʼ�����
	CreatureFactory* srf = new SheepFactory();
	srf->createCreature();

	//��ʼ�����
	CreatureFactory* wrf = new WolfFactory();
	wrf->createCreature();
}

//�����������������ǹ���ʱ������ĺ���
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

// ��Ӽ�Ⱥ
void FoodChain::addAggregation(CreatureAggregation* creatureAggregation)
{
	aggregationList.push_back(creatureAggregation);

	/* ����totalMassCanBeUsed */

}

// ɾ���ض���Ⱥ
bool FoodChain::eraseAggregation(CreatureAggregation* creatureAggregation)
{
	vector<CreatureAggregation*>::iterator aggregationIter = aggregationList.begin();
	vector<float>::iterator totalMassIter = totalMassCanBeUsed.begin();
	for ( ; aggregationIter != aggregationList.end(); aggregationIter++, totalMassIter++)
	{
		if ((*aggregationIter)->isEqual(creatureAggregation))
		{
			// ɾ����Ⱥ
			aggregationList.erase(aggregationIter);
			// ɾ����Ӧ�Ŀ���������
			totalMassCanBeUsed.erase(totalMassIter);
			return true;
		}
	}
	return false;
}

// ɾ���������ֵļ�Ⱥ
bool FoodChain::eraseAggregation(const CreatureSpecies& species)
{
	vector<CreatureAggregation*>::iterator aggregationIter = aggregationList.begin();
	vector<float>::iterator totalMassIter = totalMassCanBeUsed.begin();
	for (; aggregationIter != aggregationList.end(); aggregationIter++, totalMassIter++)
	{
		if ((*aggregationIter)->getSpecies() == species)
		{
			// ɾ����Ⱥ
			aggregationList.erase(aggregationIter);
			// ɾ����Ӧ�Ŀ���������
			totalMassCanBeUsed.erase(totalMassIter);
			return true;
		}
	}
	return false;
}

// ɾ�����м�Ⱥ
void FoodChain::eraseAllAggregations()
{
	// ɾ����Ⱥ
	aggregationList.clear();
	// ɾ����Ӧ�Ŀ���������
	totalMassCanBeUsed.clear();
}

// ��ȡ�������ֵļ�Ⱥ
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

// ��ȡ��Ⱥ��Ŀ
int FoodChain::getAggregationCount() const
{
	return aggregationList.size();
}

// ��ȡ���м�Ⱥ
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

//��ͬ������Ӱ��
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
