#include "SheepAggregation.h"

// ���²�ʳ�����嵥������
void SheepAggregation::updatePreyedSpeciesList()
{
	preyedSpeciesList.push_back(CreatureSpecies::Grass);
}

SheepAggregation::SheepAggregation()
	: CreatureAggregation(CreatureSpecies::Sheep, CreatureType::Consumer)
{
	// ���²�ʳ�����嵥
	updatePreyedSpeciesList();
}

SheepAggregation::SheepAggregation(vector<class Sheep*> members)
	: CreatureAggregation(CreatureSpecies::Sheep, CreatureType::Consumer)
{
	// ���³�Ա�б�
	for (unsigned i = 0; i < members.size(); i++)
	{
		this->members.push_back(members[i]);
	}
	// ���²�ʳ�����嵥
	updatePreyedSpeciesList();
}

SheepAggregation::SheepAggregation(const SheepAggregation& sheepAggregation)
	: CreatureAggregation(sheepAggregation.getAllMembers(), sheepAggregation.getSpecies(),
	sheepAggregation.getType())
{
	// ���²�ʳ�����嵥
	updatePreyedSpeciesList();
}

// ��ʵ��
SheepAggregation* SheepAggregation::instance = NULL;

// ����ģʽ
SheepAggregation* SheepAggregation::getInstance()
{
	if (instance == NULL)
	{
		instance = new SheepAggregation();
	}
	return instance;
}

// ����ģʽ
SheepAggregation* SheepAggregation::getInstance(vector<class Sheep*> members)
{
	if (instance == NULL)
	{
		instance = new SheepAggregation(members);
	}
	return instance;
}

// ����ģʽ
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

// ��������ĸ��岢���¼�Ⱥ
void SheepAggregation::clearingBirthAndUpdate()
{

}
