#ifndef __WOLF_AGGREGATION_h__
#define __WOLF_AGGREGATION_h__

#include "Wolf.h"
#include "CreatureAggregation.h"

class WolfAggregation : public CreatureAggregation
{
	public:
		~WolfAggregation();

		// ����ģʽ
		static WolfAggregation* getInstance();
		static WolfAggregation* getInstance(vector<class Wolf*> members);
		static WolfAggregation* getInstance(const WolfAggregation& wolfAggregation);

		// ��������ĸ��岢���¼�Ⱥ
		virtual void clearingBirthAndUpdate();

	private:
		static WolfAggregation* instance; // ��ʵ��

		// ���²�ʳ�����嵥���ǣ�
		virtual void updatePreyedSpeciesList();

		WolfAggregation();
		WolfAggregation(vector<class Wolf*> members);
		WolfAggregation(const WolfAggregation& wolfAggregation);
};

#endif // !__WOLF_AGGREGATION_h__
