#include "Grass.h"
#include "ModelValues.h"

// �ݶ���ı�ż�����
int Grass::grassIdCounter = 0;

// ���캯��
Grass::Grass() : Plant(++grassIdCounter, CreatureSpecies::Grass, CreatureType::Producer,
	ModelValues::getInstance()->getBasicMass(CreatureSpecies::Grass),
	ModelValues::getInstance()->getEnergyConversionRatio(CreatureSpecies::Grass),
	ModelValues::getInstance()->getMassConsumedPerUnitTime(CreatureSpecies::Grass),
	ModelValues::getInstance()->getMassLowerBound(CreatureSpecies::Grass),
	ModelValues::getInstance()->getMassUpperBound(CreatureSpecies::Grass),
	ModelValues::getInstance()->getBasicBirthRate(CreatureSpecies::Grass),
	ModelValues::getInstance()->getBasicDeathRate(CreatureSpecies::Grass)),
	massGainedPerUnitTime(ModelValues::getInstance()->getMassGainedPerUnitTime(CreatureSpecies::Grass))
{

}

// �������캯��
Grass::Grass(const Grass& grass) : Plant(++grassIdCounter, grass.getSpecies(), grass.getType(), grass.getMass(), grass.getEnergyConversionRatio(),
	grass.getMassConsumedPerUnitTime(), grass.getMassLowerBound(), grass.getMassUpperBound(), grass.getBirthRate(), grass.getDeathRate()),
	massGainedPerUnitTime(grass.getMassGainedPerUnitTime())
{

}

// �����ݶ���ʹ��Ĭ������
class Grass* Grass::create()
{
	Grass *grass = new (std::nothrow) Grass();
	if (grass && grass->initWithFile(ModelValues::getInstance()->getTextureFilePath(CreatureSpecies::Grass)))
	{
		grass->autorelease();
		return grass;
	}
	CC_SAFE_DELETE(grass);
	return nullptr;
}

// �����ݶ���ʹ���Զ�������
class Grass* Grass::create(const std::string& filename)
{
	Grass *grass = new (std::nothrow) Grass();
	if (grass && grass->initWithFile(filename))
	{
		grass->autorelease();
		return grass;
	}
	CC_SAFE_DELETE(grass);
	return nullptr;
}

// ����ʳ
void Grass::preyed()
{
	loseMassByPreyed(ModelValues::getInstance()->getMassLostByPreyed(CreatureSpecies::Grass));
}

// ��ȡ��λʱ���������������ӵ�����
float Grass::getMassGainedPerUnitTime() const
{
	return massGainedPerUnitTime;
}

// �޸ĵ�λʱ���������������ӵ�����
void Grass::setMassGainedPerUnitTime(const float& massGainedPerUnitTime)
{
	this->massGainedPerUnitTime = massGainedPerUnitTime;
}
