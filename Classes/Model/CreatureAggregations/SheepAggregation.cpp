#include "SheepAggregation.h"

// 更新捕食物种清单（绵羊）
void SheepAggregation::updatePreyedSpeciesList()
{
	preyedSpeciesList.push_back(CreatureSpecies::Grass);
}

SheepAggregation::SheepAggregation()
	: CreatureAggregation(CreatureSpecies::Sheep, CreatureType::Consumer)
{
	// 更新捕食物种清单
	updatePreyedSpeciesList();
}

SheepAggregation::SheepAggregation(vector<class Sheep*> members)
	: CreatureAggregation(CreatureSpecies::Sheep, CreatureType::Consumer)
{
	// 更新成员列表
	for (unsigned i = 0; i < members.size(); i++)
	{
		this->members.push_back(members[i]);
	}
	// 更新捕食物种清单
	updatePreyedSpeciesList();
}

SheepAggregation::SheepAggregation(const SheepAggregation& sheepAggregation)
	: CreatureAggregation(sheepAggregation.getAllMembers(), sheepAggregation.getSpecies(),
	sheepAggregation.getType())
{
	// 更新捕食物种清单
	updatePreyedSpeciesList();
}

// 单实例
SheepAggregation* SheepAggregation::instance = NULL;

// 单例模式
SheepAggregation* SheepAggregation::getInstance()
{
	if (instance == NULL)
	{
		instance = new SheepAggregation();
	}
	return instance;
}

// 单例模式
SheepAggregation* SheepAggregation::getInstance(vector<class Sheep*> members)
{
	if (instance == NULL)
	{
		instance = new SheepAggregation(members);
	}
	return instance;
}

// 单例模式
SheepAggregation* SheepAggregation::getInstance(const SheepAggregation& sheepAggregation)
{
	if (instance == NULL)
	{
		instance = new SheepAggregation(sheepAggregation);
	}
	return instance;
}

SheepAggregation::~SheepAggregation()
{

}

// 清算出生的个体并更新集群
void SheepAggregation::clearingBirthAndUpdate()
{

}
