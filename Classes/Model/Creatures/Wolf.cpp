#include "Wolf.h"
#include "..\Values\ModelValues.h"

// �Ƕ���ı�ż�����
int Wolf::wolfIdCounter = 0;

// ���캯��
Wolf::Wolf()
	: Animal(++wolfIdCounter, CreatureSpecies::Wolf, CreatureType::Consumer,
	ModelValues::getInstance()->getBasicMass(CreatureSpecies::Wolf),
	ModelValues::getInstance()->getEnergyConversionRatio(CreatureSpecies::Wolf),
	ModelValues::getInstance()->getBasicHealth(CreatureSpecies::Wolf),
	ModelValues::getInstance()->getRangeOfActivity(CreatureSpecies::Wolf),
	ModelValues::getInstance()->getPreyedSpeciesList(CreatureSpecies::Wolf),
	ModelValues::getInstance()->getBirthCoolDown(CreatureSpecies::Wolf)),
	healthReducedByFoodShortage(ModelValues::getInstance()->getBasicHealthReducedByFoodShortage(CreatureSpecies::Wolf))
{

}

// �������캯��
Wolf::Wolf(const Wolf& wolf) : Animal(++wolfIdCounter, wolf.getSpecies(), wolf.getType(), wolf.getMass(),
	wolf.getEnergyConversionRatio(), wolf.getHealth(), wolf.getRangeOfActivity(), wolf.getPreyedSpeciesList(),
	wolf.getBirthCoolDown()), healthReducedByFoodShortage(wolf.getHealthReducedByFoodShortage())
{
	birthCoolDown = wolf.getBirthCoolDown();
}

// �����Ƕ���ʹ��Ĭ������
class Wolf* Wolf::create()
{
	Wolf *wolf = new (std::nothrow) Wolf();
	if (wolf && wolf->initWithFile(ModelValues::getInstance()->getTextureFilePath(CreatureSpecies::Wolf)))
	{
		wolf->autorelease();
		return wolf;
	}
	CC_SAFE_DELETE(wolf);
	return nullptr;
}

// �����Ƕ���ʹ���Զ�������
class Wolf* Wolf::create(const std::string& filename)
{
	Wolf *wolf = new (std::nothrow) Wolf();
	if (wolf && wolf->initWithFile(filename))
	{
		wolf->autorelease();
		return wolf;
	}
	CC_SAFE_DELETE(wolf);
	return nullptr;
}

// ��ȡ��ʳ��ȱ�ٶ����ٵ�����ֵ
const int Wolf::getHealthReducedByFoodShortage() const
{
	return healthReducedByFoodShortage;
}

//ʳ���ȱ��Ӱ��
void Wolf::influenceOfFoodShortage()
{
	healthReducedByFoodShortage = (1.0f - intake / ModelValues::getInstance()->getAppetite(CreatureSpecies::Wolf))
		* ModelValues::getInstance()->getBasicHealthReducedByFoodShortage(CreatureSpecies::Wolf);
}
