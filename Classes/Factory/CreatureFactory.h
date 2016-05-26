#ifndef __CREATURE_FACTORY_H__
#define __CREATURE_FACTORY_H__

#include "..\Model\Creatures\Creature.h"
#include "..\Model\Ecosystem\FoodChain.h"
#include "Map\GameMapSprite.h"

class CreatureFactory 
{
public:
	CreatureFactory() {};
	CreatureFactory(int _id);
	~CreatureFactory();

	virtual void createCreature() = 0;

protected:
	int id;
	EventListenerTouchOneByOne* createListener();
};

#endif // !__CREATURE_FACTORY_H__
