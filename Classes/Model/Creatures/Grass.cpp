#include "Grass.h"
#include "ModelValues.h"

// 草对象的编号计数器
int Grass::grassIdCounter = 0;

// 构造函数
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

// 拷贝构造函数
Grass::Grass(const Grass& grass) : Plant(++grassIdCounter, grass.getSpecies(), grass.getType(), grass.getMass(), grass.getEnergyConversionRatio(),
	grass.getMassConsumedPerUnitTime(), grass.getMassLowerBound(), grass.getMassUpperBound(), grass.getBirthRate(), grass.getDeathRate()),
	massGainedPerUnitTime(grass.getMassGainedPerUnitTime())
{

}

// 创建草对象（使用默认纹理）
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

// 创建草对象（使用自定义纹理）
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

// 被捕食
void Grass::preyed()
{
	loseMassByPreyed(ModelValues::getInstance()->getMassLostByPreyed(CreatureSpecies::Grass));
}

// 获取单位时间内因光合作用增加的质量
float Grass::getMassGainedPerUnitTime() const
{
	return massGainedPerUnitTime;
}

// 修改单位时间内因光合作用增加的质量
void Grass::setMassGainedPerUnitTime(const float& massGainedPerUnitTime)
{
	this->massGainedPerUnitTime = massGainedPerUnitTime;
}
