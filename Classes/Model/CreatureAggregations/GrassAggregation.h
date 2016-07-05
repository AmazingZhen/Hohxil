#ifndef __GRASS_AGGREGATION_h__
#define __GRASS_AGGREGATION_h__

#include "Grass.h"
#include "CreatureAggregation.h"

class GrassAggregation : public CreatureAggregation
{
	public:
		~GrassAggregation();

		// 单例模式
		static GrassAggregation* getInstance();
		static GrassAggregation* getInstance(vector<class Grass*> members);
		static GrassAggregation* getInstance(const GrassAggregation& grassAggregation);

		// 清算出生的个体并更新集群
		virtual void clearingBirthAndUpdate();
		// 单位时间能量生产量（作为生产者）
		virtual float produceEnergyPerUnitTime();
		// 单位时间能量消耗量（作为生产者）
		virtual float consumeEnergyPerUnitTime();

	private:
		static GrassAggregation* instance; // 单实例

		GrassAggregation();
		GrassAggregation(vector<class Grass*> members);
		GrassAggregation(const GrassAggregation& grassAggregation);
};

#endif // !__GRASS_AGGREGATION_h__
