#ifndef __SHEEP_AGGREGATION_H__
#define __SHEEP_AGGREGATION_H__

#include "..\Creatures\Sheep.h"
#include "CreatureAggregation.h"

class SheepAggregation : public CreatureAggregation
{
	public:
		~SheepAggregation();

		// ����ģʽ
		static SheepAggregation* getInstance();
		static SheepAggregation* getInstance(vector<class Sheep*> members);
		static SheepAggregation* getInstance(const SheepAggregation& sheepAggregation);

		// ��������ĸ��岢���¼�Ⱥ
		virtual void clearingBirthAndUpdate();

	private:
		static SheepAggregation* instance; // ��ʵ��

		// ���²�ʳ�����嵥
		virtual void updatePreyedSpeciesList();

		SheepAggregation();
		SheepAggregation(vector<class Sheep*> members);
		SheepAggregation(const SheepAggregation& sheepAggregation);
};


#endif // !__SHEEP_AGGREGATION_H__
