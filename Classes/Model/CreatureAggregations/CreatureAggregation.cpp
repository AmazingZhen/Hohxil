#include "CreatureAggregation.h"

using std::vector;

// 更新捕食物种清单（默认）
void CreatureAggregation::updatePreyedSpeciesList()
{

}

CreatureAggregation::CreatureAggregation() : members(vector<Creature*>()),
	species(CreatureSpecies::UnknownSpecies), type(CreatureType::UnknownType), preyedSpeciesList(vector<CreatureSpecies>())
{
	// 更新捕食物种清单
	updatePreyedSpeciesList();
}

CreatureAggregation::CreatureAggregation(CreatureSpecies species, CreatureType type)
	: members(vector<Creature*>()), species(species), type(type), preyedSpeciesList(vector<CreatureSpecies>())
{
	// 更新捕食物种清单
	updatePreyedSpeciesList();
}

CreatureAggregation::CreatureAggregation(vector<Creature*> members, CreatureSpecies species,
	CreatureType type) : members(members), species(species), type(type),
	preyedSpeciesList(vector<CreatureSpecies>())
{
	// 更新捕食物种清单
	updatePreyedSpeciesList();
}

CreatureAggregation::CreatureAggregation(const CreatureAggregation& creatureAggregation)
	: members(creatureAggregation.getAllMembers()), species(creatureAggregation.getSpecies()),
	type(creatureAggregation.getType()), preyedSpeciesList(creatureAggregation.getPreyedSpeciesList())
{
	// 更新捕食物种清单
	updatePreyedSpeciesList();
}

CreatureAggregation::~CreatureAggregation()
{
	members.clear();
	preyedSpeciesList.clear();
}

// 添加集群成员
void CreatureAggregation::addMember(Creature* creature)
{
	members.push_back(creature);
}

// 获取集群成员数目
int CreatureAggregation::getMemberCount() const
{
	return members.size();
}

// 获取所有集群成员
vector<Creature*> CreatureAggregation::getAllMembers() const
{
	return members;
}

// 按索引获取特定集群成员
Creature* CreatureAggregation::getMemberByIndex(unsigned index) const
{
	if (index >= members.size())
	{
		return NULL;
	}
	return members[index];
}

// 按Id获取特定集群成员
Creature* CreatureAggregation::getMemberById(int id) const
{
	for (unsigned i = 0; i < members.size(); i++)
	{
		if (members[i]->getId() == id)
		{
			return members[i];
		}
	}
	return NULL;
}

// 删除所有集群成员
void CreatureAggregation::clearAllMembers()
{
	members.clear();
}

// 删除特定集群成员
bool CreatureAggregation::clearMemberByIndex(Creature* creature)
{
	for (vector<Creature*>::iterator i = members.begin(); i != members.end(); i++)
	{
		if (((Creature*)(*i))->isEqual(creature))
		{
			members.erase(i);
			return true;
		}
	}
	return false;
}

// 获取集群成员的种类
const CreatureSpecies CreatureAggregation::getSpecies() const
{
	return species;
}

// 获取集群成员的生物部分类别
const CreatureType CreatureAggregation::getType() const
{
	return type;
}

// 获取集群成员的捕食物种清单
const vector<CreatureSpecies> CreatureAggregation::getPreyedSpeciesList() const
{
	return preyedSpeciesList;
}

// 可以用于被其他消费者消费的质量
float CreatureAggregation::massCanBeConsumed()
{
	float totalMass = 0.0f;
	for (unsigned i = 0; i < members.size(); i++)
	{
		totalMass += members[i]->getMass();
	}
	return totalMass;
}

// 清算死亡的个体并更新集群
void CreatureAggregation::clearingDeathAndUpdate()
{
	for (vector<Creature*>::iterator i = members.begin(); i != members.end(); )
	{
		if ((*i)->isAlive())
		{
			i++;
		}
		else
		{
			auto scene = (*i)->getScene();
			// 将死亡的个体从地图中移除
			scene->removeChild((*i), true);
			// 将死亡的个体从集群中移除
			i = members.erase(i);
		}
	}
}

bool CreatureAggregation::isBalance()
{
	return true;
}

bool CreatureAggregation::isBelowMinimun()
{
	return false;
}

void CreatureAggregation::influenceToLastGrade()
{

}

// 判断两个集群对象是否相同
bool CreatureAggregation::isEqual(const CreatureAggregation* creatureAggregation)
{
	return (species == creatureAggregation->getSpecies() && type == creatureAggregation->getType());
}
