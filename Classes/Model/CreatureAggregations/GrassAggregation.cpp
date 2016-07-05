#include "GrassAggregation.h"
#include "ModelValues.h"

GrassAggregation::GrassAggregation()
	: CreatureAggregation(CreatureSpecies::Grass, CreatureType::Producer)
{

}

GrassAggregation::GrassAggregation(vector<class Grass*> members)
	: CreatureAggregation(CreatureSpecies::Grass, CreatureType::Producer)
{
	// 更新成员列表
	for (unsigned i = 0; i < members.size(); i++)
	{
		this->members.push_back(members[i]);
	}
}

GrassAggregation::GrassAggregation(const GrassAggregation& grassAggregation)
	: CreatureAggregation(grassAggregation.getAllMembers(), grassAggregation.getSpecies(),
	grassAggregation.getType())
{

}

GrassAggregation::~GrassAggregation()
{

}

// 单实例
GrassAggregation* GrassAggregation::instance = NULL;

// 单例模式
GrassAggregation* GrassAggregation::getInstance()
{
	if (instance == NULL)
	{
		instance = new GrassAggregation();
	}
	return instance;
}

// 单例模式
GrassAggregation* GrassAggregation::getInstance(vector<class Grass*> members)
{
	if (instance == NULL)
	{
		instance = new GrassAggregation(members);
	}
	return instance;
}

// 单例模式
GrassAggregation* GrassAggregation::getInstance(const GrassAggregation& grassAggregation)
{
	if (instance == NULL)
	{
		instance = new GrassAggregation(grassAggregation);
	}
	return instance;
}

// 清算出生的个体并更新集群
void GrassAggregation::clearingBirthAndUpdate()
{

}

// 单位时间能量生产量（作为生产者）
float GrassAggregation::produceEnergyPerUnitTime()
{
	float totalEnergyProduced = 0.0f;
	for (unsigned i = 0; i < members.size(); i++)
	{
		totalEnergyProduced += ((class Grass*)members[i])->getMassGainedPerUnitTime();
	}
	return totalEnergyProduced;
}


// 单位时间能量消耗量（作为生产者或消费者）
float GrassAggregation::consumeEnergyPerUnitTime()
{
	float totalEnergyConsumed = 0.0f;
	for (unsigned i = 0; i < members.size(); i++)
	{
		totalEnergyConsumed += ((class Grass*)members[i])->getMassConsumedPerUnitTime();
	}
	return totalEnergyConsumed;
}
