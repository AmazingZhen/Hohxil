#ifndef __FOOD_CHAIN_H__
#define __FOOD_CHAIN_H__

#include <vector>
#include "..\CreatureAggregations\CreatureAggregation.h"
#include "..\..\Map\LargeMap.h"
#include "..\..\Map\GameMap.h"

using std::vector;

// 食物链类
class FoodChain
{
	public:
		FoodChain();
		~FoodChain();

		// 单实例模式
		static FoodChain* getInstance();

		//对食物链进行初始化
		void init();

		//刷新时间的操作
		float getRefreshInterval();
		float getCurrentRefreshInterval();
		void addCurrentRefreshInterval(float interval);

		// 添加集群
		void addAggregation(CreatureAggregation* creatureAggregation);
		// 删除特定集群
		bool eraseAggregation(CreatureAggregation* creatureAggregation);
		// 删除给定物种的集群
		bool eraseAggregation(const CreatureSpecies& species);
		// 删除所有集群
		void eraseAllAggregations();
		// 获取给定物种的集群
		CreatureAggregation* getAggregation(const CreatureSpecies& species);
		// 获取集群数目
		int getAggregationCount() const;
		// 获取所有集群
		const vector<CreatureAggregation*> getAllAggregations() const;

		void clearing();

		//不同动作的影响
		void sheepEatGrassInfluence();
		void eraseDiedSheep();

		void wolfEatSheepInfluence(float numRequired);
		float energyConvertion(float orignalEnergy);

	private:
		static FoodChain* instance; // 单实例
		LargeMap* largeMap;
		GameMap* grassLand;

		//草原生态系统基础刷新时间：Model的定时刷新，相对于世界刷新时间而言的
		float currentRefreshInterval;

		// 集群列表
		vector<CreatureAggregation*> aggregationList;
		// 每个集群可供消费的质量
		vector<float> totalMassCanBeUsed;
};

#endif // !__FOOD_CHAIN_H__
