#ifndef __GRASS_H__
#define __GRASS_H__

#include "Plant.h"

// ����
class Grass : public Plant
{
	public:
		// �����ݶ���ʹ��Ĭ������
		static Grass* create();
		// �����ݶ���ʹ���Զ�������
		static Grass* create(const std::string& filename);

		// ����ʳ
		virtual void preyed();
    
        // growth
        virtual void grow();
    
        // breed
        void breed();


		// ��ȡ��λʱ���������������ӵ�����
		float getMassGainedPerUnitTime() const;
		// �޸ĵ�λʱ���������������ӵ�����
		void setMassGainedPerUnitTime(const float& massGainedPerUnitTime);

	private:
		static int grassIdCounter; // �ݶ���ı�ż�����

		float massGainedPerUnitTime; // ��λʱ���������������ӵ�����

		// ���캯��
		Grass();
		// �������캯��
		Grass(const Grass& grass);
};

#endif // !__GRASS_H__
