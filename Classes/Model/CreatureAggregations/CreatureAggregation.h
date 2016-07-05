#ifndef __CREATURE_AGGREGATION_H__
#define __CREATURE_AGGREGATION_H__

#include <vector>
#include <string>
#include "Creature.h"

using std::vector;

// ���ּ�Ⱥ�ࣨ����ࣩ
class CreatureAggregation
{
	public:
		CreatureAggregation();
		CreatureAggregation(CreatureSpecies species, CreatureType type);
		CreatureAggregation(vector<Creature*> members, CreatureSpecies species, CreatureType type);
		CreatureAggregation(const CreatureAggregation& creatureAggregation);
		~CreatureAggregation();

		// ��Ӽ�Ⱥ��Ա
		void addMember(Creature* creature);
		// ��ȡ��Ⱥ��Ա��Ŀ
		int getMemberCount() const;
		// ��ȡ���м�Ⱥ��Ա
		vector<Creature*> getAllMembers() const;
		// ��������ȡ�ض���Ⱥ��Ա
		Creature* getMemberByIndex(unsigned index) const;
		// ��Id��ȡ�ض���Ⱥ��Ա
		Creature* getMemberById(int id) const;
		// ɾ�����м�Ⱥ��Ա
		void clearAllMembers();
		// ɾ���ض���Ⱥ��Ա
		bool clearMemberByIndex(Creature* creature);

		// ��ȡ��Ⱥ��Ա������
		const CreatureSpecies getSpecies() const;
		// ��ȡ��Ⱥ��Ա�����ﲿ�����
		const CreatureType getType() const;
		// ��ȡ��Ⱥ��Ա�Ĳ�ʳ�����嵥
		const vector<CreatureSpecies> getPreyedSpeciesList() const;

		// �������ڱ��������������ѵ�����
		virtual float massCanBeConsumed();
		// ��������ĸ��岢���¼�Ⱥ
		virtual void clearingBirthAndUpdate() = 0;
		// ���������ĸ��岢���¼�Ⱥ
		virtual void clearingDeathAndUpdate();
		virtual bool isBalance();
		virtual bool isBelowMinimun();
		virtual void influenceToLastGrade();

		// �ж�������Ⱥ�����Ƿ���ͬ
		bool isEqual(const CreatureAggregation* creatureAggregation);

	protected:
		vector<Creature*> members; // ��Ⱥ�еĳ�Ա
		CreatureSpecies species; // ��Ⱥ��Ա������
		CreatureType type; // ��Ⱥ��Ա�����ﲿ�����
		vector<CreatureSpecies> preyedSpeciesList; // ��ʳ�����嵥

	private:
		// ���²�ʳ�����嵥
		virtual void updatePreyedSpeciesList();
};

#endif // !__CREATURE_AGGREGATION_H__
