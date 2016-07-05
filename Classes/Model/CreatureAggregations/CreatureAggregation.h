#ifndef __CREATURE_AGGREGATION_H__
#define __CREATURE_AGGREGATION_H__

#include <vector>
#include <string>
#include "Creature.h"

using std::vector;

// 物种集群类（虚基类）
class CreatureAggregation
{
	public:
		CreatureAggregation();
		CreatureAggregation(CreatureSpecies species, CreatureType type);
		CreatureAggregation(vector<Creature*> members, CreatureSpecies species, CreatureType type);
		CreatureAggregation(const CreatureAggregation& creatureAggregation);
		~CreatureAggregation();

		// 添加集群成员
		void addMember(Creature* creature);
		// 获取集群成员数目
		int getMemberCount() const;
		// 获取所有集群成员
		vector<Creature*> getAllMembers() const;
		// 按索引获取特定集群成员
		Creature* getMemberByIndex(unsigned index) const;
		// 按Id获取特定集群成员
		Creature* getMemberById(int id) const;
		// 删除所有集群成员
		void clearAllMembers();
		// 删除特定集群成员
		bool clearMemberByIndex(Creature* creature);

		// 获取集群成员的种类
		const CreatureSpecies getSpecies() const;
		// 获取集群成员的生物部分类别
		const CreatureType getType() const;
		// 获取集群成员的捕食物种清单
		const vector<CreatureSpecies> getPreyedSpeciesList() const;

		// 可以用于被其他消费者消费的质量
		virtual float massCanBeConsumed();
		// 清算出生的个体并更新集群
		virtual void clearingBirthAndUpdate() = 0;
		// 清算死亡的个体并更新集群
		virtual void clearingDeathAndUpdate();
		virtual bool isBalance();
		virtual bool isBelowMinimun();
		virtual void influenceToLastGrade();

		// 判断两个集群对象是否相同
		bool isEqual(const CreatureAggregation* creatureAggregation);

	protected:
		vector<Creature*> members; // 集群中的成员
		CreatureSpecies species; // 集群成员的种类
		CreatureType type; // 集群成员的生物部分类别
		vector<CreatureSpecies> preyedSpeciesList; // 捕食物种清单

	private:
		// 更新捕食物种清单
		virtual void updatePreyedSpeciesList();
};

#endif // !__CREATURE_AGGREGATION_H__
