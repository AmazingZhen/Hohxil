#include "Creature.h"

Creature::Creature() : id(0), species(CreatureSpecies::UnknownSpecies), type(CreatureType::UnknownType),
	mass(0.0f), energyConversionRatio(0.0f), alive(true)
{
}

Creature::Creature(int id, CreatureSpecies species, CreatureType type, float mass, float energyConversionRatio)
	: id(id), species(species), type(type), mass(mass), energyConversionRatio(energyConversionRatio), alive(true)
{
}

Creature::Creature(const Creature& creature) : id(creature.getId()), species(creature.getSpecies()),
	type(creature.getType()), mass(creature.getMass()), energyConversionRatio(creature.getEnergyConversionRatio()), alive(creature.isAlive())
{
}

// 获取生物的编号
const int Creature::getId() const
{
	return id;
}

// 获取生物对象的种类
const CreatureSpecies Creature::getSpecies() const
{
	return species;
}

// 获取生物对象的生物部分类别
const CreatureType Creature::getType() const
{
	return type;
}

// 获取生物的质量
float Creature::getMass() const
{
	return mass;
}

// 获取生物的能量转化率
const float Creature::getEnergyConversionRatio() const
{
	return energyConversionRatio;
}

// 判断两个生物对象是否相同
bool Creature::isEqual(const Creature* creature) const
{
	return (species == creature->getSpecies() && id == creature->getId());
}

// 获取生物的存活状态
bool Creature::isAlive() const {
	return alive;
}
