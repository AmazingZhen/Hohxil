#include "WolfAggregation.h"

// ���²�ʳ�����嵥���ǣ�
void WolfAggregation::updatePreyedSpeciesList()
{
	preyedSpeciesList.push_back(CreatureSpecies::Sheep);
}

WolfAggregation::WolfAggregation()
	: CreatureAggregation(CreatureSpecies::Wolf, CreatureType::Consumer)
{
	// ���²�ʳ�����嵥
	updatePreyedSpeciesList();
}

WolfAggregation::WolfAggregation(vector<class Wolf*> members)
	: CreatureAggregation(CreatureSpecies::Wolf, CreatureType::Consumer)
{
	// ���³�Ա�б�
	for (unsigned i = 0; i < members.size(); i++)
	{
		this->members.push_back(members[i]);
	}
	// ���²�ʳ�����嵥
	updatePreyedSpeciesList();
}

WolfAggregation::WolfAggregation(const WolfAggregation& wolfAggregation)
	: CreatureAggregation(wolfAggregation.getAllMembers(), wolfAggregation.getSpecies(),
	wolfAggregation.getType())
{
	// ���²�ʳ�����嵥
	updatePreyedSpeciesList();
}

// ��ʵ��
WolfAggregation* WolfAggregation::instance = NULL;

// ����ģʽ
WolfAggregation* WolfAggregation::getInstance()
{
	if (instance == NULL)
	{
		instance = new WolfAggregation();
	}
	return instance;
}

// ����ģʽ
WolfAggregation* WolfAggregation::getInstance(vector<class Wolf*> members)
{
	if (instance == NULL)
	{
		instance = new WolfAggregation(members);
	}
	return instance;
}

// ����ģʽ
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


// ��������ĸ��岢���¼�Ⱥ
void WolfAggregation::clearingBirthAndUpdate()
{

}
