#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <vector>
#include <cocos2d.h>
#include "Creature.h"

using std::vector;
using cocos2d::Size;

// 动物类（虚基类）
class Animal : public Creature
{
	public:
		Animal();
		Animal(int id, CreatureSpecies species, CreatureType type, float mass, float energyConversionRatio,
			float health, float rangeOfActivity, vector<CreatureSpecies> preyedSpeciesList, float birthCoolDown);
		Animal(const Animal& animal);

		// 捕食
		virtual void prey(Creature* preyed);
		// 被捕食
		virtual void preyed();

		// 获取动物对象的生命值
		int getHealth() const;
		// 修改动物对象的生命值
		void setHealth(const float& health);
		// 获取动物对象当前的寿命进度
		float getLifeProgress() const;
		// 修改动物对象当前的寿命进度
		void setLifeProgress(const float& lifeProgress);
		// 获取动物对象当前已进食的量
		float getIntake() const;
		// 修改动物对象当前已进食的量
		void setIntake(const float& intake);
		// 获取动物对象的活动范围
		float getRangeOfActivity() const;
		// 修改动物对象的活动范围
		void setRangeOfActivity(const float& rangeOfActivity);
		// 获取动物对象的捕食物种清单
		vector<CreatureSpecies> getPreyedSpeciesList() const;
		// 获取动物对象的生育冷却时间
		float getBirthCoolDown() const;
		// 修改动物对象的生育冷却时间
		void setBirthCoolDown(const float& birthCoolDown);

		// 移动
		virtual void move();
		//食物短缺的影响
		virtual void influenceOfFoodShortage() = 0;

		// Used in listener
		bool isSelected;

	protected:
		int health; // 生命值
		float lifeProgress; // 寿命进度
		float intake; // 当前已进食量
		float rangeOfActivity; // 活动范围
		vector<CreatureSpecies> preyedSpeciesList; // 捕食物种清单
		float birthCoolDown; // 生育冷却时间
};

#endif // !__ANIMAL_H
