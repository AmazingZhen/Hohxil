#ifndef __MODEL_VALUES_H__
#define __MODEL_VALUES_H__

#define SPECIES_KINDS 5

#include <vector>
#include "Creature.h"

using std::vector;
using std::string;

// 模型数值类
class ModelValues
{
	public:
		~ModelValues();

		// 单例模式
		static ModelValues* getInstance();

		/* 获取数值的函数 */
		// 获取对应生物的能量转化率
		const float getEnergyConversionRatio(const CreatureSpecies& species) const;
		// 获取对应生物的基础质量
		const float getBasicMass(const CreatureSpecies& species) const;
		// 获取对应生物的纹理贴图文件路径
		const string getTextureFilePath(const CreatureSpecies& species) const;

		// 获取对应生物的基础生命值
		const float getBasicHealth(const CreatureSpecies& species) const;
		// 获取对应生物的寿命
		const float getLifespan(const CreatureSpecies& species) const;
		// 获取对应生物的食量需求
		const float getAppetite(const CreatureSpecies& species) const;
		// 获取对应生物单位时间减少的生命值
		const float getReducedHealthPerUnitTime(const CreatureSpecies& species) const;
		// 获取对应生物的活动范围
		const float getRangeOfActivity(const CreatureSpecies& species) const;
		// 获取对应生物的捕食清单
		const vector<CreatureSpecies> getPreyedSpeciesList(const CreatureSpecies& species) const;
		// 获取对应生物因食物短缺造成的额外生命值减少基础量
		const int getBasicHealthReducedByFoodShortage(const CreatureSpecies& species) const;
		// 获取对应生物的生育冷却时间
		const float getBirthCoolDown(const CreatureSpecies& species) const;

		// 获取对应生物单位时间因呼吸作用消耗的质量
		const float getMassConsumedPerUnitTime(const CreatureSpecies& species) const;
		// 获取对应生物单位时间因光合作用增加的质量
		const float getMassGainedPerUnitTime(const CreatureSpecies& species) const;
		// 获取对应生物的质量下限
		const float getMassLowerBound(const CreatureSpecies& species) const;
		// 获取对应生物的质量上限
		const float getMassUpperBound(const CreatureSpecies& species) const;
		// 获取对应生物的基础出生率
		const float getBasicBirthRate(const CreatureSpecies& species) const;
		// 获取对应生物的基础死亡率
		const float getBasicDeathRate(const CreatureSpecies& species) const;
		// 获取对应生物被捕食损失的质量
		const float getMassLostByPreyed(const CreatureSpecies& species) const;

	private:
		static ModelValues* instance; // 单实例

		// 构造函数
		ModelValues();

		/* 数值 */
		float energyConversionRatio[SPECIES_KINDS]; // 各种生物的能量转化率
		float basicMass[SPECIES_KINDS]; // 各种生物的基础质量
		string textureFilePath[SPECIES_KINDS]; // 各种生物的纹理贴图文件路径

		float basicHealth[SPECIES_KINDS]; // 各种生物的基础生命值（只对动物有意义，植物同一为0.0f）
		float lifespan[SPECIES_KINDS]; // 各种生物的寿命（只对动物有意义，植物统一为0.0f）
		float appetite[SPECIES_KINDS]; // 各种生物的食量需求（只对动物有意义，植物统一为0.0f）
		float reducedHealthPerUnitTime[SPECIES_KINDS]; // 各种生物单位时间减少的生命值（只对动物有意义，植物统一为0.0f）
		float rangeOfActivity[SPECIES_KINDS]; // 各种生物的活动范围（圆半径，只对动物有意义，植物统一为0.0f）
		vector<CreatureSpecies> preyedSpeciesList[SPECIES_KINDS]; // 各种生物的捕食清单（只对动物有意义，植物统一为空）
		int basicHealthReducedByFoodShortage[SPECIES_KINDS]; // 各种生物因食物短缺造成的额外生命值减少基础量（只对动物有意义，植物统一为0）
		float birthCoolDown[SPECIES_KINDS]; // 各种生物的生育冷却时间（只对动物有意义，植物统一为0.0f）
		
		float massConsumedPerUnitTime[SPECIES_KINDS]; // 各种生物单位时间因呼吸作用消耗的质量（只对植物有意义，动物统一为0.0f）
		float massGainedPerUnitTime[SPECIES_KINDS]; // 各种生物单位时间因光合作用增加的质量（只对植物有意义，动物统一为0.0f）
		float massLowerBound[SPECIES_KINDS]; // 各种生物的质量下限（只对植物有意义，动物统一为0.0f）
		float massUpperBound[SPECIES_KINDS]; // 各种生物的质量上限（只对植物有意义，动物统一为0.0f）
		float basicBirthRate[SPECIES_KINDS]; // 各种生物的基础出生率（只对植物有意义，动物统一为0.0f）
		float basicDeathRate[SPECIES_KINDS]; // 各种生物的基础死亡率（只对植物有意义，动物统一为0.0f）
		float massLostByPreyed[SPECIES_KINDS]; // 各种生物被捕食损失的质量（只对植物有意义，动物统一为自身质量）

		/* 从本地读入数值的函数 */
		// 从本地读入数值
		void loadDynamicValues();
		// 固定修改数值
		void loadStaticValues();
};

#endif // __VALUES_H__
