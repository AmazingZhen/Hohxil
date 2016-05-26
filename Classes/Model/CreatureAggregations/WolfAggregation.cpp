#include "WolfAggregation.h"

// 更新捕食物种清单（狼）
void WolfAggregation::updatePreyedSpeciesList()
{
	preyedSpeciesList.push_back(CreatureSpecies::Sheep);
}

WolfAggregation::WolfAggregation()
	: CreatureAggregation(CreatureSpecies::Wolf, CreatureType::Consumer)
{
	// 更新捕食物种清单
	updatePreyedSpeciesList();
}

WolfAggregation::WolfAggregation(vector<class Wolf*> members)
	: CreatureAggregation(CreatureSpecies::Wolf, CreatureType::Consumer)
{
	// 更新成员列表
	for (unsigned i = 0; i < members.size(); i++)
	{
		this->members.push_back(members[i]);
	}
	// 更新捕食物种清单
	updatePreyedSpeciesList();
}

WolfAggregation::WolfAggregation(const WolfAggregation& wolfAggregation)
	: CreatureAggregation(wolfAggregation.getAllMembers(), wolfAggregation.getSpecies(),
	wolfAggregation.getType())
{
	// 更新捕食物种清单
	updatePreyedSpeciesList();
}

// 单实例
WolfAggregation* WolfAggregation::instance = NULL;

// 单例模式
WolfAggregation* WolfAggregation::getInstance()
{
	if (instance == NULL)
	{
		instance = new WolfAggregation();
	}
	return instance;
}

// 单例模式
WolfAggregation* WolfAggregation::getInstance(vector<class Wolf*> members)
{
	if (instance == NULL)
	{
		instance = new WolfAggregation(members);
	}
	return instance;
}

// 单例模式
WolfAggregation* WolfAggregation::getInstance(const WolfAggregation& wolfAggregation)
{
	if (instance == NULL)
	{
		instance = new WolfAggregation(wolfAggregation);
	}
	return instance;
}

WolfAggregation::~WolfAggregation()
{

}


// 清算出生的个体并更新集群
void WolfAggregation::clearingBirthAndUpdate()
{

}
