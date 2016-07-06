#ifndef __CREATURE_H__
#define __CREATURE_H__

#include "cocos2d.h"

// 生物部分类别
enum CreatureType { UnknownType, Producer, Consumer, Decomposer };

// 生物种类
enum CreatureSpecies { UnknownSpecies, Grass, Tree, Sheep, Wolf };

// 生物类（虚基类）
class Creature : public cocos2d::Sprite
{
	public:
		Creature();
		Creature(int id, CreatureSpecies species, CreatureType type, float mass, float energyConversionRatio);
		Creature(const Creature& creature);

		// 被捕食
		virtual void preyed() = 0;
		// 获取生物的编号
		const int getId() const;
		// 获取生物对象的种类
		const CreatureSpecies getSpecies() const;
		// 获取生物对象的生物部分类别
		const CreatureType getType() const;
		// 获取生物的质量
		float getMass() const;
		// 获取生物的能量转化率
		const float getEnergyConversionRatio() const;
		// 获取生物的存活状态
		bool isAlive() const;

		// 判断两个生物对象是否相同
		bool isEqual(const Creature* creature) const;

	protected:
		// 生物种类与编号共同构成一个Creature对象的主码
		int id; // 生物对象在同一物种中的编号
		CreatureSpecies species; // 生物种类
		CreatureType type; // 生物部分类别

		float mass; // 质量

		float energyConversionRatio; // 能量转化率

		bool alive; // 是否存活
};

#endif // __CREATURE_H__
