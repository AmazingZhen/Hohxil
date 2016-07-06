#ifndef __SHEEP_AGGREGATION_H__
#define __SHEEP_AGGREGATION_H__

#include "..\Creatures\Sheep.h"
#include "CreatureAggregation.h"

class SheepAggregation : public CreatureAggregation
{
	public:
		~SheepAggregation();

		// 单例模式
		static SheepAggregation* getInstance();
		static SheepAggregation* getInstance(vector<class Sheep*> members);
		static SheepAggregation* getInstance(const SheepAggregation& sheepAggregation);

		// 清算出生的个体并更新集群
		virtual void clearingBirthAndUpdate();

	private:
		static SheepAggregation* instance; // 单实例

		// 更新捕食物种清单
		virtual void updatePreyedSpeciesList();

		SheepAggregation();
		SheepAggregation(vector<class Sheep*> members);
		SheepAggregation(const SheepAggregation& sheepAggregation);
};


#endif // !__SHEEP_AGGREGATION_H__
