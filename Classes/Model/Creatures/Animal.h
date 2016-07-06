#ifndef __ANIMAL_H__
#define __ANIMAL_H__

#include <vector>
#include <cocos2d.h>
#include "Creature.h"

using std::vector;
using cocos2d::Size;

// �����ࣨ����ࣩ
class Animal : public Creature
{
	public:
		Animal();
		Animal(int id, CreatureSpecies species, CreatureType type, float mass, float energyConversionRatio,
			float health, float rangeOfActivity, vector<CreatureSpecies> preyedSpeciesList, float birthCoolDown);
		Animal(const Animal& animal);

		// ��ʳ
		virtual void prey(Creature* preyed);
		// ����ʳ
		virtual void preyed();

		// ��ȡ������������ֵ
		int getHealth() const;
		// �޸Ķ�����������ֵ
		void setHealth(const float& health);
		// ��ȡ�������ǰ����������
		float getLifeProgress() const;
		// �޸Ķ������ǰ����������
		void setLifeProgress(const float& lifeProgress);
		// ��ȡ�������ǰ�ѽ�ʳ����
		float getIntake() const;
		// �޸Ķ������ǰ�ѽ�ʳ����
		void setIntake(const float& intake);
		// ��ȡ�������Ļ��Χ
		float getRangeOfActivity() const;
		// �޸Ķ������Ļ��Χ
		void setRangeOfActivity(const float& rangeOfActivity);
		// ��ȡ�������Ĳ�ʳ�����嵥
		vector<CreatureSpecies> getPreyedSpeciesList() const;
		// ��ȡ��������������ȴʱ��
		float getBirthCoolDown() const;
		// �޸Ķ�������������ȴʱ��
		void setBirthCoolDown(const float& birthCoolDown);

		// �ƶ�
		virtual void move();
		//ʳ���ȱ��Ӱ��
		virtual void influenceOfFoodShortage() = 0;

		// Used in listener
		bool isSelected;

	protected:
		int health; // ����ֵ
		float lifeProgress; // ��������
		float intake; // ��ǰ�ѽ�ʳ��
		float rangeOfActivity; // ���Χ
		vector<CreatureSpecies> preyedSpeciesList; // ��ʳ�����嵥
		float birthCoolDown; // ������ȴʱ��
};

#endif // !__ANIMAL_H
