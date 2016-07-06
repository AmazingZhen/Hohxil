#ifndef __WOLF_H__
#define __WOLF_H__

#include "Animal.h"

// ����
class Wolf : public Animal
{
	public:
		// �����Ƕ���ʹ��Ĭ������
		static Wolf* create();
		// �����Ƕ���ʹ���Զ�������
		static Wolf* create(const std::string& filename);

		// ��ȡ��ʳ��ȱ�ٶ����ٵ�����ֵ
		const int getHealthReducedByFoodShortage() const;

		//ʳ���ȱ��Ӱ��
		virtual void influenceOfFoodShortage();

		// ��ֳ
		void breed(Wolf *other);

	private:
		static int wolfIdCounter; // �Ƕ���ı�ż�����

		// ����ֵ���Ʊ���
		int healthReducedByFoodShortage; // ʳ��ȱ��-->Ѫ������

		// ���캯��
		Wolf();
		// �������캯��
		Wolf(const Wolf& wolf);
};

#endif // !__WOLF_H__
