#ifndef __GRASS_AGGREGATION_h__
#define __GRASS_AGGREGATION_h__

#include "Grass.h"
#include "CreatureAggregation.h"

class GrassAggregation : public CreatureAggregation
{
	public:
		~GrassAggregation();

		// ����ģʽ
		static GrassAggregation* getInstance();
		static GrassAggregation* getInstance(vector<class Grass*> members);
		static GrassAggregation* getInstance(const GrassAggregation& grassAggregation);

		// ��������ĸ��岢���¼�Ⱥ
		virtual void clearingBirthAndUpdate();
		// ��λʱ����������������Ϊ�����ߣ�
		virtual float produceEnergyPerUnitTime();
		// ��λʱ����������������Ϊ�����ߣ�
		virtual float consumeEnergyPerUnitTime();

	private:
		static GrassAggregation* instance; // ��ʵ��

		GrassAggregation();
		GrassAggregation(vector<class Grass*> members);
		GrassAggregation(const GrassAggregation& grassAggregation);
};

#endif // !__GRASS_AGGREGATION_h__
