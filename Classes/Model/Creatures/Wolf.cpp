#include "Wolf.h"
#include "..\Values\ModelValues.h"

// 狼对象的编号计数器
int Wolf::wolfIdCounter = 0;

// 构造函数
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

// 拷贝构造函数
Wolf::Wolf(const Wolf& wolf) : Animal(++wolfIdCounter, wolf.getSpecies(), wolf.getType(), wolf.getMass(),
	wolf.getEnergyConversionRatio(), wolf.getHealth(), wolf.getRangeOfActivity(), wolf.getPreyedSpeciesList(),
	wolf.getBirthCoolDown()), healthReducedByFoodShortage(wolf.getHealthReducedByFoodShortage())
{
	birthCoolDown = wolf.getBirthCoolDown();
}

// 创建狼对象（使用默认纹理）
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

// 创建狼对象（使用自定义纹理）
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

// 获取因食物缺少而减少的生命值
const int Wolf::getHealthReducedByFoodShortage() const
{
	return healthReducedByFoodShortage;
}

//食物短缺的影响
void Wolf::influenceOfFoodShortage()
{
	healthReducedByFoodShortage = (1.0f - intake / ModelValues::getInstance()->getAppetite(CreatureSpecies::Wolf))
		* ModelValues::getInstance()->getBasicHealthReducedByFoodShortage(CreatureSpecies::Wolf);
}
