#ifndef __WOLF_AGGREGATION_h__
#define __WOLF_AGGREGATION_h__

#include "Wolf.h"
#include "CreatureAggregation.h"

class WolfAggregation : public CreatureAggregation
{
	public:
		~WolfAggregation();

		// 单例模式
		static WolfAggregation* getInstance();
		static WolfAggregation* getInstance(vector<class Wolf*> members);
		static WolfAggregation* getInstance(const WolfAggregation& wolfAggregation);

		// 清算出生的个体并更新集群
		virtual void clearingBirthAndUpdate();

	private:
		static WolfAggregation* instance; // 单实例

		// 更新捕食物种清单（狼）
		virtual void updatePreyedSpeciesList();

		WolfAggregation();
		WolfAggregation(vector<class Wolf*> members);
		WolfAggregation(const WolfAggregation& wolfAggregation);
};

#endif // !__WOLF_AGGREGATION_h__
