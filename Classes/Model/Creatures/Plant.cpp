#include "Plant.h"

Plant::Plant() : Creature(), massLostByPreyed(0.0f)
{

}

Plant::Plant(int id, CreatureSpecies species, CreatureType type, float mass, float energyConversionRatio,
	float massConsumedPerUnitTime, float massLowerBound, float massUpperBound, float birthRate, float deathRate)
	: Creature(id, species, type, mass, energyConversionRatio), massLostByPreyed(0.0f), massConsumedPerUnitTime(massConsumedPerUnitTime),
	massLowerBound(massLowerBound), massUpperBound(massUpperBound), birthRate(birthRate), deathRate(deathRate)
{

}

Plant::Plant(const Plant& plant) : Creature(plant.getId(), plant.getSpecies(), plant.getType(), plant.getMass(),
	plant.getEnergyConversionRatio()), massLostByPreyed(plant.getMassLostByPreyed()),
	massConsumedPerUnitTime(plant.getMassConsumedPerUnitTime()), massLowerBound(plant.getMassLowerBound()),
	massUpperBound(plant.getMassUpperBound()), birthRate(plant.getBirthRate()), deathRate(plant.getDeathRate())
{

}

// ��ȡ���������������
float Plant::getMassLostByPreyed() const
{
	return massLostByPreyed;
}

// �޸ı��������������
void Plant::loseMassByPreyed(const float& mass)
{
	if (massLostByPreyed + mass > this->mass)
	{
		// ֲ���������
		alive = false;
		return;
	}
	// ֲ������Ҵ棬��ʧ��������
	massLostByPreyed += mass;
}

// ��ȡ����ֲ�ﵥλʱ����������������ĵ�����
float Plant::getMassConsumedPerUnitTime() const
{
	return massConsumedPerUnitTime;
}

// �޸ĸ���ֲ�ﵥλʱ����������������ĵ�����
void Plant::setMassConsumedPerUnitTime(const float& massConsumedPerUnitTime)
{
	this->massConsumedPerUnitTime = massConsumedPerUnitTime;
}

// ��ȡ����ֲ�����������
float Plant::getMassLowerBound() const
{
	return massLowerBound;
}

// �޸ĸ���ֲ�����������
void Plant::setMassLowerBound(const float& massLowerBound)
{
	this->massLowerBound = massLowerBound;
}

// ��ȡ����ֲ�����������
float Plant::getMassUpperBound() const
{
	return massUpperBound;
}

// �޸ĸ���ֲ�����������
void Plant::setMassUpperBound(const float& massUpperBound)
{
	this->massUpperBound = massUpperBound;
}

// ��ȡ����ֲ��ĳ�����
float Plant::getBirthRate() const
{
	return birthRate;
}

// �޸ĸ���ֲ��ĳ�����
void Plant::setBirthRate(const float& birthRate)
{
	this->birthRate = birthRate;
}

// ��ȡ����ֲ���������
float Plant::getDeathRate() const
{
	return deathRate;
}

// �޸ĸ���ֲ���������
void Plant::setDeathRate(const float& deathRate)
{
	this->deathRate = deathRate;
}
