#pragma once
#ifndef __PLANT_H__
#define __PLANT_H__

#include "Creature.h"

// 植物类（虚基类）
class Plant : public Creature
{
	public:
		Plant();
		Plant(int id, CreatureSpecies species, CreatureType type, float mass, float energyConversionRatio,
			float massConsumedPerUnitTime, float massLowerBound, float massUpperBound, float birthRate, float deathRate);
		Plant(const Plant& plant);

		// 被捕食
		virtual void preyed() = 0;

		// 获取被动物摄入的质量
		float getMassLostByPreyed() const;
		// 修改被动物摄入的质量
		void loseMassByPreyed(const float& mass);
		// 获取该种植物单位时间内因呼吸作用消耗的质量
		float getMassConsumedPerUnitTime() const;
		// 修改该种植物单位时间内因呼吸作用消耗的质量
		void setMassConsumedPerUnitTime(const float& massConsumedPerUnitTime);
		// 获取该种植物的质量下限
		float getMassLowerBound() const;
		// 修改该种植物的质量下限
		void setMassLowerBound(const float& massLowerBound);
		// 获取该种植物的质量上限
		float getMassUpperBound() const;
		// 修改该种植物的质量上限
		void setMassUpperBound(const float& massUpperBound);
		// 获取该种植物的出生率
		float getBirthRate() const;
		// 修改该种植物的出生率
		void setBirthRate(const float& birthRate);
		// 获取该种植物的死亡率
		float getDeathRate() const;
		// 修改该种植物的死亡率
		void setDeathRate(const float& deathRate);

	protected:
		float massLostByPreyed; // 被动物摄入的质量
		
		float massConsumedPerUnitTime; // 单位时间内因呼吸作用消耗的质量

		float massLowerBound; // 质量下限
		float massUpperBound; // 质量上限

		float birthRate; // 出生率
		float deathRate; // 死亡率
};

#endif
