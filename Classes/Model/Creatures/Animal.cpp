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

// 捕食
void Animal::prey(Creature* preyed)
{
	if (getIntake() >= ModelValues::getInstance()->getAppetite(species))
	{
		// 已吃饱，不再进食
		return;
	}

	/* 猎物被捕食 */
	preyed->preyed();

	// 捕食
	// 获取猎物种类
	CreatureSpecies preyedSpecies = preyed->getSpecies();
	// 获取猎物的能量转化率
	float energyConversionRatio = ModelValues::getInstance()->getEnergyConversionRatio(preyedSpecies);
	// 计算捕食过程中能够获得的最大能量
	float maxEnergyGain = energyConversionRatio * ModelValues::getInstance()->getMassLostByPreyed(preyedSpecies);
	// 计算实际的能量需求
	float energyDemand = ModelValues::getInstance()->getAppetite(species) - getIntake();
	// 计算实际取得的能量
	float energyGain = MIN(energyDemand, maxEnergyGain);
	setIntake(getIntake() + energyGain);
}

// 被捕食
void Animal::preyed()
{
	// 生命值减至0
	health = 0;
	// 死亡
	alive = false;
}

// 获取动物对象当前的寿命进度
float Animal::getLifeProgress() const
{
	return lifeProgress;
}

// 修改动物对象当前的寿命进度
void Animal::setLifeProgress(const float& lifeProgress)
{
	this->lifeProgress = lifeProgress;
}

// 获取动物对象的生命值
int Animal::getHealth() const
{
	return health;
}

// 修改动物对象的生命值
void Animal::setHealth(const float& health)
{
	this->health = health;
}

// 获取动物对象当前已进食的量
float Animal::getIntake() const
{
	return intake;
}

// 修改动物对象当前已进食的量
void Animal::setIntake(const float& intake)
{
	this->intake = intake;
}

// 获取动物对象的活动范围
float Animal::getRangeOfActivity() const
{
	return rangeOfActivity;
}

// 修改动物对象的活动范围
void Animal::setRangeOfActivity(const float& rangeOfActivity)
{
	this->rangeOfActivity = rangeOfActivity;
}

// 获取动物对象的捕食物种清单
vector<CreatureSpecies> Animal::getPreyedSpeciesList() const
{
	return preyedSpeciesList;
}

// 获取动物对象的生育冷却时间
float Animal::getBirthCoolDown() const
{
	return birthCoolDown;
}

// 修改动物对象的生育冷却时间
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
