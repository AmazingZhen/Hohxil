#include "Animal.h"
#include "..\Values\ModelValues.h"
#include "..\..\Map\LargeMap.h"

using std::vector;

Animal::Animal() : Creature(), lifeProgress(0.0f), intake(0.0f), rangeOfActivity(0.0f), preyedSpeciesList(vector<CreatureSpecies>()),
birthCoolDown(0.0f), isSelected(false)
{

}

Animal::Animal(int id, CreatureSpecies species, CreatureType type, float mass, float energyConversionRatio, float health,
	float rangeOfActivity, vector<CreatureSpecies> preyedSpeciesList, float birthCoolDown)
	: Creature(id, species, type, mass, energyConversionRatio), health(health), lifeProgress(0.0f), intake(0.0f),
	rangeOfActivity(rangeOfActivity), preyedSpeciesList(preyedSpeciesList), birthCoolDown(birthCoolDown), isSelected(false)
{

}

Animal::Animal(const Animal& animal) : Creature(animal.getId(), animal.getSpecies(), animal.getType(), animal.getMass(),
	animal.getEnergyConversionRatio()), health(animal.getHealth()), lifeProgress(animal.getLifeProgress()), intake(animal.getIntake()),
	rangeOfActivity(animal.getRangeOfActivity()), preyedSpeciesList(animal.getPreyedSpeciesList()), birthCoolDown(animal.getBirthCoolDown()), isSelected(false)
{

}

// ��ʳ
void Animal::prey(Creature* preyed)
{
	if (getIntake() >= ModelValues::getInstance()->getAppetite(species))
	{
		// �ѳԱ������ٽ�ʳ
		return;
	}

	/* ���ﱻ��ʳ */
	preyed->preyed();

	// ��ʳ
	// ��ȡ��������
	CreatureSpecies preyedSpecies = preyed->getSpecies();
	// ��ȡ���������ת����
	float energyConversionRatio = ModelValues::getInstance()->getEnergyConversionRatio(preyedSpecies);
	// ���㲶ʳ�������ܹ���õ��������
	float maxEnergyGain = energyConversionRatio * ModelValues::getInstance()->getMassLostByPreyed(preyedSpecies);
	// ����ʵ�ʵ���������
	float energyDemand = ModelValues::getInstance()->getAppetite(species) - getIntake();
	// ����ʵ��ȡ�õ�����
	float energyGain = MIN(energyDemand, maxEnergyGain);
	setIntake(getIntake() + energyGain);
}

// ����ʳ
void Animal::preyed()
{
	// ����ֵ����0
	health = 0;
	// ����
	alive = false;
}

// ��ȡ�������ǰ����������
float Animal::getLifeProgress() const
{
	return lifeProgress;
}

// �޸Ķ������ǰ����������
void Animal::setLifeProgress(const float& lifeProgress)
{
	this->lifeProgress = lifeProgress;
}

// ��ȡ������������ֵ
int Animal::getHealth() const
{
	return health;
}

// �޸Ķ�����������ֵ
void Animal::setHealth(const float& health)
{
	this->health = health;
}

// ��ȡ�������ǰ�ѽ�ʳ����
float Animal::getIntake() const
{
	return intake;
}

// �޸Ķ������ǰ�ѽ�ʳ����
void Animal::setIntake(const float& intake)
{
	this->intake = intake;
}

// ��ȡ�������Ļ��Χ
float Animal::getRangeOfActivity() const
{
	return rangeOfActivity;
}

// �޸Ķ������Ļ��Χ
void Animal::setRangeOfActivity(const float& rangeOfActivity)
{
	this->rangeOfActivity = rangeOfActivity;
}

// ��ȡ�������Ĳ�ʳ�����嵥
vector<CreatureSpecies> Animal::getPreyedSpeciesList() const
{
	return preyedSpeciesList;
}

// ��ȡ��������������ȴʱ��
float Animal::getBirthCoolDown() const
{
	return birthCoolDown;
}

// �޸Ķ�������������ȴʱ��
void Animal::setBirthCoolDown(const float& birthCoolDown)
{
	this->birthCoolDown = birthCoolDown;
}

//�ƶ�
void Animal::move(const Size& boundary)
{
	// ��ȡ��ǰλ��
	float currentX = getPosition().x;
	float currentY = getPosition().y;

	// ��ȡ��λ��x���½�
	float xMin = MAX(currentX - sqrt(rangeOfActivity), 0.0f);
	// ��ȡ��λ��x���Ͻ�
	float xMax = MIN(currentX + sqrt(rangeOfActivity), boundary.width);
	// ��ȡ��λ��x
	float x = (float)randomNum((double)xMin, (double)xMax);
	assert((x - currentX) * (x - currentX) < rangeOfActivity * rangeOfActivity);

	// ����|y0 - y|���Ͻ�
	float tempUpperBound = sqrt(rangeOfActivity * rangeOfActivity - (x - currentX) * (x - currentX));
	// ��ȡ��λ��y���½�
	float yMin = MAX(currentY - tempUpperBound, 0.0f);
	// ��ȡ��λ��y���Ͻ�
	float yMax = MIN(currentY + tempUpperBound, boundary.width);
	// ��ȡ��λ��y
	float y = (float)randomNum((double)yMin, (double)yMax);
	assert((x - currentX) * (x - currentX) + (y - currentY) * (y - currentY) <= rangeOfActivity * rangeOfActivity);

	// �ƶ�����λ��
	//setPosition(Vec2(x, y));

	auto act = MoveTo::create(1.0f, Vec2(x, y));
	this->runAction(act);
}
