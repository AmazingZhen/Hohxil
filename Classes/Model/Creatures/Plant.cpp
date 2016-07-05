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

// 获取被动物摄入的质量
float Plant::getMassLostByPreyed() const
{
	return massLostByPreyed;
}

// 修改被动物摄入的质量
void Plant::loseMassByPreyed(const float& mass)
{
	if (massLostByPreyed + mass > this->mass)
	{
		// 植物对象死亡
		alive = false;
		return;
	}
	// 植物对象幸存，损失部分质量
	massLostByPreyed += mass;
}

// 获取该种植物单位时间内因呼吸作用消耗的质量
float Plant::getMassConsumedPerUnitTime() const
{
	return massConsumedPerUnitTime;
}

// 修改该种植物单位时间内因呼吸作用消耗的质量
void Plant::setMassConsumedPerUnitTime(const float& massConsumedPerUnitTime)
{
	this->massConsumedPerUnitTime = massConsumedPerUnitTime;
}

// 获取该种植物的质量下限
float Plant::getMassLowerBound() const
{
	return massLowerBound;
}

// 修改该种植物的质量下限
void Plant::setMassLowerBound(const float& massLowerBound)
{
	this->massLowerBound = massLowerBound;
}

// 获取该种植物的质量上限
float Plant::getMassUpperBound() const
{
	return massUpperBound;
}

// 修改该种植物的质量上限
void Plant::setMassUpperBound(const float& massUpperBound)
{
	this->massUpperBound = massUpperBound;
}

// 获取该种植物的出生率
float Plant::getBirthRate() const
{
	return birthRate;
}

// 修改该种植物的出生率
void Plant::setBirthRate(const float& birthRate)
{
	this->birthRate = birthRate;
}

// 获取该种植物的死亡率
float Plant::getDeathRate() const
{
	return deathRate;
}

// 修改该种植物的死亡率
void Plant::setDeathRate(const float& deathRate)
{
	this->deathRate = deathRate;
}
