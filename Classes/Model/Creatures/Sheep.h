#ifndef __SHEEP_H__
#define __SHEEP_H__

#include <cocos2d.h>
#include "Animal.h"

using cocos2d::Size;

// ������
class Sheep : public Animal
{
	public:
		// �����������ʹ��Ĭ������
		static Sheep* create();
		// �����������ʹ���Զ�������
		static Sheep* create(const std::string& filename);

		// ��ȡ��ʳ��ȱ�ٶ����ٵ�����ֵ
		const int getHealthReducedByFoodShortage() const;

		//ʳ���ȱ��Ӱ��
		virtual void influenceOfFoodShortage();

		void breed(Sheep *other);

	private:
		static int sheepIdCounter; // �������ı�ż�����

		// ����ֵ���Ʊ���
		int healthReducedByFoodShortage; // ʳ��ȱ��-->Ѫ������

		// ���캯��
		Sheep();
		// �������캯��
		Sheep(const Sheep& sheep);
};

#endif // !__SHEEP_H__
