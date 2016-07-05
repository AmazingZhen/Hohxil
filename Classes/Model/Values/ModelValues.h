#ifndef __MODEL_VALUES_H__
#define __MODEL_VALUES_H__

#define SPECIES_KINDS 5

#include <vector>
#include "Creature.h"

using std::vector;
using std::string;

// ģ����ֵ��
class ModelValues
{
	public:
		~ModelValues();

		// ����ģʽ
		static ModelValues* getInstance();

		/* ��ȡ��ֵ�ĺ��� */
		// ��ȡ��Ӧ���������ת����
		const float getEnergyConversionRatio(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ����Ļ�������
		const float getBasicMass(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ�����������ͼ�ļ�·��
		const string getTextureFilePath(const CreatureSpecies& species) const;

		// ��ȡ��Ӧ����Ļ�������ֵ
		const float getBasicHealth(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ���������
		const float getLifespan(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ�����ʳ������
		const float getAppetite(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ���ﵥλʱ����ٵ�����ֵ
		const float getReducedHealthPerUnitTime(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ����Ļ��Χ
		const float getRangeOfActivity(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ����Ĳ�ʳ�嵥
		const vector<CreatureSpecies> getPreyedSpeciesList(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ������ʳ���ȱ��ɵĶ�������ֵ���ٻ�����
		const int getBasicHealthReducedByFoodShortage(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ�����������ȴʱ��
		const float getBirthCoolDown(const CreatureSpecies& species) const;

		// ��ȡ��Ӧ���ﵥλʱ��������������ĵ�����
		const float getMassConsumedPerUnitTime(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ���ﵥλʱ�������������ӵ�����
		const float getMassGainedPerUnitTime(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ�������������
		const float getMassLowerBound(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ�������������
		const float getMassUpperBound(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ����Ļ���������
		const float getBasicBirthRate(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ����Ļ���������
		const float getBasicDeathRate(const CreatureSpecies& species) const;
		// ��ȡ��Ӧ���ﱻ��ʳ��ʧ������
		const float getMassLostByPreyed(const CreatureSpecies& species) const;

	private:
		static ModelValues* instance; // ��ʵ��

		// ���캯��
		ModelValues();

		/* ��ֵ */
		float energyConversionRatio[SPECIES_KINDS]; // �������������ת����
		float basicMass[SPECIES_KINDS]; // ��������Ļ�������
		string textureFilePath[SPECIES_KINDS]; // ���������������ͼ�ļ�·��

		float basicHealth[SPECIES_KINDS]; // ��������Ļ�������ֵ��ֻ�Զ��������壬ֲ��ͬһΪ0.0f��
		float lifespan[SPECIES_KINDS]; // ���������������ֻ�Զ��������壬ֲ��ͳһΪ0.0f��
		float appetite[SPECIES_KINDS]; // ���������ʳ������ֻ�Զ��������壬ֲ��ͳһΪ0.0f��
		float reducedHealthPerUnitTime[SPECIES_KINDS]; // �������ﵥλʱ����ٵ�����ֵ��ֻ�Զ��������壬ֲ��ͳһΪ0.0f��
		float rangeOfActivity[SPECIES_KINDS]; // ��������Ļ��Χ��Բ�뾶��ֻ�Զ��������壬ֲ��ͳһΪ0.0f��
		vector<CreatureSpecies> preyedSpeciesList[SPECIES_KINDS]; // ��������Ĳ�ʳ�嵥��ֻ�Զ��������壬ֲ��ͳһΪ�գ�
		int basicHealthReducedByFoodShortage[SPECIES_KINDS]; // ����������ʳ���ȱ��ɵĶ�������ֵ���ٻ�������ֻ�Զ��������壬ֲ��ͳһΪ0��
		float birthCoolDown[SPECIES_KINDS]; // ���������������ȴʱ�䣨ֻ�Զ��������壬ֲ��ͳһΪ0.0f��
		
		float massConsumedPerUnitTime[SPECIES_KINDS]; // �������ﵥλʱ��������������ĵ�������ֻ��ֲ�������壬����ͳһΪ0.0f��
		float massGainedPerUnitTime[SPECIES_KINDS]; // �������ﵥλʱ�������������ӵ�������ֻ��ֲ�������壬����ͳһΪ0.0f��
		float massLowerBound[SPECIES_KINDS]; // ����������������ޣ�ֻ��ֲ�������壬����ͳһΪ0.0f��
		float massUpperBound[SPECIES_KINDS]; // ����������������ޣ�ֻ��ֲ�������壬����ͳһΪ0.0f��
		float basicBirthRate[SPECIES_KINDS]; // ��������Ļ��������ʣ�ֻ��ֲ�������壬����ͳһΪ0.0f��
		float basicDeathRate[SPECIES_KINDS]; // ��������Ļ��������ʣ�ֻ��ֲ�������壬����ͳһΪ0.0f��
		float massLostByPreyed[SPECIES_KINDS]; // �������ﱻ��ʳ��ʧ��������ֻ��ֲ�������壬����ͳһΪ����������

		/* �ӱ��ض�����ֵ�ĺ��� */
		// �ӱ��ض�����ֵ
		void loadDynamicValues();
		// �̶��޸���ֵ
		void loadStaticValues();
};

#endif // __VALUES_H__
