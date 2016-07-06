#ifndef __FOOD_CHAIN_H__
#define __FOOD_CHAIN_H__

#include <vector>
#include "..\CreatureAggregations\CreatureAggregation.h"
#include "..\..\Map\LargeMap.h"
#include "..\..\Map\GameMap.h"

using std::vector;

// ʳ������
class FoodChain
{
	public:
		FoodChain();
		~FoodChain();

		// ��ʵ��ģʽ
		static FoodChain* getInstance();

		//��ʳ�������г�ʼ��
		void init();

		//ˢ��ʱ��Ĳ���
		float getRefreshInterval();
		float getCurrentRefreshInterval();
		void addCurrentRefreshInterval(float interval);

		// ��Ӽ�Ⱥ
		void addAggregation(CreatureAggregation* creatureAggregation);
		// ɾ���ض���Ⱥ
		bool eraseAggregation(CreatureAggregation* creatureAggregation);
		// ɾ���������ֵļ�Ⱥ
		bool eraseAggregation(const CreatureSpecies& species);
		// ɾ�����м�Ⱥ
		void eraseAllAggregations();
		// ��ȡ�������ֵļ�Ⱥ
		CreatureAggregation* getAggregation(const CreatureSpecies& species);
		// ��ȡ��Ⱥ��Ŀ
		int getAggregationCount() const;
		// ��ȡ���м�Ⱥ
		const vector<CreatureAggregation*> getAllAggregations() const;

		void clearing();

		//��ͬ������Ӱ��
		void sheepEatGrassInfluence();
		void eraseDiedSheep();

		void wolfEatSheepInfluence(float numRequired);
		float energyConvertion(float orignalEnergy);

	private:
		static FoodChain* instance; // ��ʵ��
		LargeMap* largeMap;
		GameMap* grassLand;

		//��ԭ��̬ϵͳ����ˢ��ʱ�䣺Model�Ķ�ʱˢ�£����������ˢ��ʱ����Ե�
		float currentRefreshInterval;

		// ��Ⱥ�б�
		vector<CreatureAggregation*> aggregationList;
		// ÿ����Ⱥ�ɹ����ѵ�����
		vector<float> totalMassCanBeUsed;
};

#endif // !__FOOD_CHAIN_H__
