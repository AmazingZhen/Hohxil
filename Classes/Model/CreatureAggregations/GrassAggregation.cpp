#include "GrassAggregation.h"
#include "ModelValues.h"

GrassAggregation::GrassAggregation()
	: CreatureAggregation(CreatureSpecies::Grass, CreatureType::Producer)
{

}

GrassAggregation::GrassAggregation(vector<class Grass*> members)
	: CreatureAggregation(CreatureSpecies::Grass, CreatureType::Producer)
{
	// ���³�Ա�б�
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

// ��ʵ��
GrassAggregation* GrassAggregation::instance = NULL;

// ����ģʽ
GrassAggregation* GrassAggregation::getInstance()
{
	if (instance == NULL)
	{
		instance = new GrassAggregation();
	}
	return instance;
}

// ����ģʽ
GrassAggregation* GrassAggregation::getInstance(vector<class Grass*> members)
{
	if (instance == NULL)
	{
		instance = new GrassAggregation(members);
	}
	return instance;
}

// ����ģʽ
GrassAggregation* GrassAggregation::getInstance(const GrassAggregation& grassAggregation)
{
	if (instance == NULL)
	{
		instance = new GrassAggregation(grassAggregation);
	}
	return instance;
}

// ��������ĸ��岢���¼�Ⱥ
void GrassAggregation::clearingBirthAndUpdate()
{

}

// ��λʱ����������������Ϊ�����ߣ�
float GrassAggregation::produceEnergyPerUnitTime()
{
	float totalEnergyProduced = 0.0f;
	for (unsigned i = 0; i < members.size(); i++)
	{
		totalEnergyProduced += ((class Grass*)members[i])->getMassGainedPerUnitTime();
	}
	return totalEnergyProduced;
}


// ��λʱ����������������Ϊ�����߻������ߣ�
float GrassAggregation::consumeEnergyPerUnitTime()
{
	float totalEnergyConsumed = 0.0f;
	for (unsigned i = 0; i < members.size(); i++)
	{
		totalEnergyConsumed += ((class Grass*)members[i])->getMassConsumedPerUnitTime();
	}
	return totalEnergyConsumed;
}
