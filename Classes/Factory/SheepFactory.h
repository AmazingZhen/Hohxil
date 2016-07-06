#ifndef __SHEEP_FACTORY_H__
#define __SHEEP_FACTORY_H__

#include "CreatureFactory.h"
#include "Map\GameMap.h"

class SheepFactory : public CreatureFactory
{
	public:
		SheepFactory() {};
		SheepFactory(int _id) { id = _id; };

		virtual void createCreature();

		// added by XuYongzhe
		// add a sheep in gameMap
		virtual void createSheep(Scene* gameScene, Vec2 &pos);
};

#endif // !__SHEEP_FACTORY_H__
