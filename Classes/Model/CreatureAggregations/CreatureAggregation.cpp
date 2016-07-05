#include "CreatureAggregation.h"

using std::vector;

// ���²�ʳ�����嵥��Ĭ�ϣ�
void CreatureAggregation::updatePreyedSpeciesList()
{

}

CreatureAggregation::CreatureAggregation() : members(vector<Creature*>()),
	species(CreatureSpecies::UnknownSpecies), type(CreatureType::UnknownType), preyedSpeciesList(vector<CreatureSpecies>())
{
	// ���²�ʳ�����嵥
	updatePreyedSpeciesList();
}

CreatureAggregation::CreatureAggregation(CreatureSpecies species, CreatureType type)
	: members(vector<Creature*>()), species(species), type(type), preyedSpeciesList(vector<CreatureSpecies>())
{
	// ���²�ʳ�����嵥
	updatePreyedSpeciesList();
}

CreatureAggregation::CreatureAggregation(vector<Creature*> members, CreatureSpecies species,
	CreatureType type) : members(members), species(species), type(type),
	preyedSpeciesList(vector<CreatureSpecies>())
{
	// ���²�ʳ�����嵥
	updatePreyedSpeciesList();
}

CreatureAggregation::CreatureAggregation(const CreatureAggregation& creatureAggregation)
	: members(creatureAggregation.getAllMembers()), species(creatureAggregation.getSpecies()),
	type(creatureAggregation.getType()), preyedSpeciesList(creatureAggregation.getPreyedSpeciesList())
{
	// ���²�ʳ�����嵥
	updatePreyedSpeciesList();
}

CreatureAggregation::~CreatureAggregation()
{
	members.clear();
	preyedSpeciesList.clear();
}

// ��Ӽ�Ⱥ��Ա
void CreatureAggregation::addMember(Creature* creature)
{
	members.push_back(creature);
}

// ��ȡ��Ⱥ��Ա��Ŀ
int CreatureAggregation::getMemberCount() const
{
	return members.size();
}

// ��ȡ���м�Ⱥ��Ա
vector<Creature*> CreatureAggregation::getAllMembers() const
{
	return members;
}

// ��������ȡ�ض���Ⱥ��Ա
Creature* CreatureAggregation::getMemberByIndex(unsigned index) const
{
	if (index >= members.size())
	{
		return NULL;
	}
	return members[index];
}

// ��Id��ȡ�ض���Ⱥ��Ա
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

// ɾ�����м�Ⱥ��Ա
void CreatureAggregation::clearAllMembers()
{
	members.clear();
}

// ɾ���ض���Ⱥ��Ա
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

// ��ȡ��Ⱥ��Ա������
const CreatureSpecies CreatureAggregation::getSpecies() const
{
	return species;
}

// ��ȡ��Ⱥ��Ա�����ﲿ�����
const CreatureType CreatureAggregation::getType() const
{
	return type;
}

// ��ȡ��Ⱥ��Ա�Ĳ�ʳ�����嵥
const vector<CreatureSpecies> CreatureAggregation::getPreyedSpeciesList() const
{
	return preyedSpeciesList;
}

// �������ڱ��������������ѵ�����
float CreatureAggregation::massCanBeConsumed()
{
	float totalMass = 0.0f;
	for (unsigned i = 0; i < members.size(); i++)
	{
		totalMass += members[i]->getMass();
	}
	return totalMass;
}

// ���������ĸ��岢���¼�Ⱥ
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
			// �������ĸ���ӵ�ͼ���Ƴ�
			scene->removeChild((*i), true);
			// �������ĸ���Ӽ�Ⱥ���Ƴ�
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

// �ж�������Ⱥ�����Ƿ���ͬ
bool CreatureAggregation::isEqual(const CreatureAggregation* creatureAggregation)
{
	return (species == creatureAggregation->getSpecies() && type == creatureAggregation->getType());
}
