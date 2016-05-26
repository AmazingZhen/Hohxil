#include "ModelValues.h"

using std::vector;

// 从本地读入数值
void ModelValues::loadDynamicValues()
{
	/* 从本地读入数值 */


}

// 固定修改数值
void ModelValues::loadStaticValues()
{
	energyConversionRatio[0] = 0.0f;
	energyConversionRatio[1] = 0.2f;
	energyConversionRatio[2] = 0.3f;
	energyConversionRatio[3] = 0.1f;
	energyConversionRatio[4] = 0.05f;
	basicMass[0] = 0.0f;
	basicMass[1] = 50.0f;
	basicMass[2] = 500.0f;
	basicMass[3] = 100.0f;
	basicMass[4] = 150.0f;
	textureFilePath[0] = "";
	textureFilePath[1] = "creature/grass.png";
	textureFilePath[2] = "CloseNormal.png";
	textureFilePath[3] = "creature/sheep.png";
	textureFilePath[4] = "creature/wolf.png";

	basicHealth[0] = 0.0f;
	basicHealth[1] = 0.0f;
	basicHealth[2] = 0.0f;
	basicHealth[3] = 2000.0f;
	basicHealth[4] = 2500.0f;
	lifespan[0] = 0.0f;
	lifespan[1] = 0.0f;
	lifespan[2] = 0.0f;
	lifespan[3] = 20.0f;
	lifespan[4] = 15.0f;
	appetite[0] = 0.0f;
	appetite[1] = 0.0f;
	appetite[2] = 0.0f;
	appetite[3] = 30.0f;
	appetite[4] = 60.0f;
	reducedHealthPerUnitTime[0] = 0.0f;
	reducedHealthPerUnitTime[1] = 0.0f;
	reducedHealthPerUnitTime[2] = 0.0f;
	reducedHealthPerUnitTime[3] = 0.2f;
	reducedHealthPerUnitTime[4] = 0.5f;
	rangeOfActivity[0] = 0.0f;
	rangeOfActivity[1] = 0.0f;
	rangeOfActivity[2] = 0.0f;
	rangeOfActivity[3] = 10.0f;
	rangeOfActivity[4] = 50.0f;
	preyedSpeciesList[3].push_back(CreatureSpecies::Grass);
	preyedSpeciesList[4].push_back(CreatureSpecies::Sheep);
	basicHealthReducedByFoodShortage[0] = 0;
	basicHealthReducedByFoodShortage[1] = 0;
	basicHealthReducedByFoodShortage[2] = 0;
	basicHealthReducedByFoodShortage[3] = 200;
	basicHealthReducedByFoodShortage[4] = 500;
	birthCoolDown[0] = 0;
	birthCoolDown[1] = 0;
	birthCoolDown[2] = 0;
	birthCoolDown[3] = 200.0f;
	birthCoolDown[4] = 400.0f;

	massConsumedPerUnitTime[0] = 0.0f;
	massConsumedPerUnitTime[1] = 0.2f;
	massConsumedPerUnitTime[2] = 0.5f;
	massConsumedPerUnitTime[3] = 0.0f;
	massConsumedPerUnitTime[4] = 0.0f;
	massGainedPerUnitTime[0] = 0.0f;
	massGainedPerUnitTime[1] = 0.5f;
	massGainedPerUnitTime[2] = 0.8f;
	massGainedPerUnitTime[3] = 0.0f;
	massGainedPerUnitTime[4] = 0.0f;
	massLowerBound[0] = 0.0f;
	massLowerBound[1] = 10.0f;
	massLowerBound[2] = 100.0f;
	massLowerBound[3] = 0.0f;
	massLowerBound[4] = 0.0f;
	massUpperBound[0] = 0.0f;
	massUpperBound[1] = 60.0f;
	massUpperBound[2] = 600.0f;
	massUpperBound[3] = 0.0f;
	massUpperBound[4] = 0.0f;
	basicBirthRate[0] = 0.0f;
	basicBirthRate[1] = 0.2f;
	basicBirthRate[2] = 0.1f;
	basicBirthRate[3] = 0.0f;
	basicBirthRate[4] = 0.0f;
	basicDeathRate[0] = 0.0f;
	basicDeathRate[1] = 0.1f;
	basicDeathRate[2] = 0.05f;
	basicDeathRate[3] = 0.0f;
	basicDeathRate[4] = 0.0f;
	massLostByPreyed[0] = 0.0f;
	massLostByPreyed[1] = 30.0f;
	massLostByPreyed[2] = 20.0f;
	massLostByPreyed[3] = basicMass[3];
	massLostByPreyed[4] = basicMass[4];
}

// 构造函数
ModelValues::ModelValues()
{
	// loadDynamicValues();
	loadStaticValues();
}

ModelValues::~ModelValues()
{
	for (int i = 0; i < SPECIES_KINDS; i++)
	{
		preyedSpeciesList[i].clear();
	}
}

// 单实例
ModelValues* ModelValues::instance = NULL;

// 单例模式
ModelValues* ModelValues::getInstance()
{
	if (instance == NULL)
	{
		instance = new ModelValues();
	}
	return instance;
}

// 获取对应生物的能量转化率
const float ModelValues::getEnergyConversionRatio(const CreatureSpecies& species) const
{
	return energyConversionRatio[species];
}

// 获取对应生物的基础质量
const float ModelValues::getBasicMass(const CreatureSpecies& species) const
{
	return basicMass[species];
}

// 获取对应生物的纹理贴图文件路径
const string ModelValues::getTextureFilePath(const CreatureSpecies& species) const
{
	return textureFilePath[species];
}

// 获取对应生物的基础生命值
const float ModelValues::getBasicHealth(const CreatureSpecies& species) const
{
	return basicHealth[species];
}

// 获取对应生物的寿命
const float ModelValues::getLifespan(const CreatureSpecies& species) const
{
	return lifespan[species];
}

// 获取对应生物的食量需求
const float ModelValues::getAppetite(const CreatureSpecies& species) const
{
	return appetite[species];
}

// 获取对应生物单位时间减少的生命值
const float ModelValues::getReducedHealthPerUnitTime(const CreatureSpecies& species) const
{
	return reducedHealthPerUnitTime[species];
}

// 获取对应生物的活动范围
const float ModelValues::getRangeOfActivity(const CreatureSpecies& species) const
{
	return rangeOfActivity[species];
}

// 获取对应生物的捕食清单
const vector<CreatureSpecies> ModelValues::getPreyedSpeciesList(const CreatureSpecies& species) const
{
	return preyedSpeciesList[species];
}

// 获取对应生物因食物短缺造成的额外生命值减少基础量
const int ModelValues::getBasicHealthReducedByFoodShortage(const CreatureSpecies& species) const
{
	return basicHealthReducedByFoodShortage[species];
}

// 获取对应生物的生育冷却时间
const float ModelValues::getBirthCoolDown(const CreatureSpecies& species) const
{
	return birthCoolDown[species];
}

// 获取对应生物单位时间因呼吸作用消耗的质量
const float ModelValues::getMassConsumedPerUnitTime(const CreatureSpecies& species) const
{
	return massConsumedPerUnitTime[species];
}

// 获取对应生物单位时间因光合作用增加的质量
const float ModelValues::getMassGainedPerUnitTime(const CreatureSpecies& species) const
{
	return massGainedPerUnitTime[species];
}

// 获取对应生物的质量下限
const float ModelValues::getMassLowerBound(const CreatureSpecies& species) const
{
	return massLowerBound[species];
}

// 获取对应生物的质量上限
const float ModelValues::getMassUpperBound(const CreatureSpecies& species) const
{
	return massUpperBound[species];
}

// 获取对应生物的基础出生率
const float ModelValues::getBasicBirthRate(const CreatureSpecies& species) const
{
	return basicBirthRate[species];
}

// 获取对应生物的基础死亡率
const float ModelValues::getBasicDeathRate(const CreatureSpecies& species) const
{
	return basicDeathRate[species];
}

// 获取对应生物被捕食损失的质量
const float ModelValues::getMassLostByPreyed(const CreatureSpecies& species) const
{
	return massLostByPreyed[species];
}
