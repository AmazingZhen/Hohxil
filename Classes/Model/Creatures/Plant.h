#pragma once
#ifndef __PLANT_H__
#define __PLANT_H__

#include "Creature.h"

// ֲ���ࣨ����ࣩ
class Plant : public Creature
{
	public:
		Plant();
		Plant(int id, CreatureSpecies species, CreatureType type, float mass, float energyConversionRatio,
			float massConsumedPerUnitTime, float massLowerBound, float massUpperBound, float birthRate, float deathRate);
		Plant(const Plant& plant);

		// ����ʳ
		virtual void preyed() = 0;

		// ��ȡ���������������
		float getMassLostByPreyed() const;
		// �޸ı��������������
		void loseMassByPreyed(const float& mass);
		// ��ȡ����ֲ�ﵥλʱ����������������ĵ�����
		float getMassConsumedPerUnitTime() const;
		// �޸ĸ���ֲ�ﵥλʱ����������������ĵ�����
		void setMassConsumedPerUnitTime(const float& massConsumedPerUnitTime);
		// ��ȡ����ֲ�����������
		float getMassLowerBound() const;
		// �޸ĸ���ֲ�����������
		void setMassLowerBound(const float& massLowerBound);
		// ��ȡ����ֲ�����������
		float getMassUpperBound() const;
		// �޸ĸ���ֲ�����������
		void setMassUpperBound(const float& massUpperBound);
		// ��ȡ����ֲ��ĳ�����
		float getBirthRate() const;
		// �޸ĸ���ֲ��ĳ�����
		void setBirthRate(const float& birthRate);
		// ��ȡ����ֲ���������
		float getDeathRate() const;
		// �޸ĸ���ֲ���������
		void setDeathRate(const float& deathRate);

	protected:
		float massLostByPreyed; // ���������������
		
		float massConsumedPerUnitTime; // ��λʱ����������������ĵ�����

		float massLowerBound; // ��������
		float massUpperBound; // ��������

		float birthRate; // ������
		float deathRate; // ������
};

#endif
