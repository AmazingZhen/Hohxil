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

void Animal::move()
{
	if (this->getBirthCoolDown() < ModelValues::getInstance()->getBirthCoolDown(this->species)) {
		auto birthCD = this->getBirthCoolDown();
		this->setBirthCoolDown(birthCD + 20);
	}

	this->lifeProgress++;
	if (lifeProgress >= 15) {
		this->setHealth(0);
	}

	Size boundary = Director::getInstance()->getVisibleSize();

	float currentX = getPosition().x;
	float currentY = getPosition().y;

	float x;
	do {
		x = randomNum(currentX - rangeOfActivity, currentX + rangeOfActivity);
	} while (x < 0 || x > boundary.width);

	float y;
	do {
		y = randomNum(currentY - rangeOfActivity, currentY + rangeOfActivity);
	} while (y < 0 || y > boundary.height);

	if ((Scene*)this->getParent() == Director::getInstance()->getRunningScene()) {
		auto act = MoveTo::create(1.0f, Vec2(x, y));
		this->runAction(act);
	}
	else {
		this->setPosition(Vec2(x, y));
	}
}
