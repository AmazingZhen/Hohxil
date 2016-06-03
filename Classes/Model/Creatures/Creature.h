#ifndef __CREATURE_H__
#define __CREATURE_H__

#include "cocos2d.h"

// ���ﲿ�����
enum CreatureType { UnknownType, Producer, Consumer, Decomposer };

// ��������
enum CreatureSpecies { UnknownSpecies, Grass, Tree, Sheep, Wolf };

// �����ࣨ����ࣩ
class Creature : public cocos2d::Sprite
{
	public:
		Creature();
		Creature(int id, CreatureSpecies species, CreatureType type, float mass, float energyConversionRatio);
		Creature(const Creature& creature);

		// ����ʳ
		virtual void preyed() = 0;
		// ��ȡ����ı��
		const int getId() const;
		// ��ȡ������������
		const CreatureSpecies getSpecies() const;
		// ��ȡ�����������ﲿ�����
		const CreatureType getType() const;
		// ��ȡ���������
		float getMass() const;
		// ��ȡ���������ת����
		const float getEnergyConversionRatio() const;
		// ��ȡ����Ĵ��״̬
		bool isAlive() const;

		// �ж�������������Ƿ���ͬ
		bool isEqual(const Creature* creature) const;

	protected:
		// �����������Ź�ͬ����һ��Creature���������
		int id; // ���������ͬһ�����еı��
		CreatureSpecies species; // ��������
		CreatureType type; // ���ﲿ�����

		float mass; // ����

		float energyConversionRatio; // ����ת����

		bool alive; // �Ƿ���
};

#endif // __CREATURE_H__
