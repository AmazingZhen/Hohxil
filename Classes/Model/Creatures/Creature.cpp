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

// ��ȡ����ı��
const int Creature::getId() const
{
	return id;
}

// ��ȡ������������
const CreatureSpecies Creature::getSpecies() const
{
	return species;
}

// ��ȡ�����������ﲿ�����
const CreatureType Creature::getType() const
{
	return type;
}

// ��ȡ���������
float Creature::getMass() const
{
	return mass;
}

// ��ȡ���������ת����
const float Creature::getEnergyConversionRatio() const
{
	return energyConversionRatio;
}

// �ж�������������Ƿ���ͬ
bool Creature::isEqual(const Creature* creature) const
{
	return (species == creature->getSpecies() && id == creature->getId());
}

// ��ȡ����Ĵ��״̬
bool Creature::isAlive() const {
	return alive;
}
