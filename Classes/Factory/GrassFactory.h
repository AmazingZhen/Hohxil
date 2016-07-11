#ifndef __GRASS_FACTORY_H__
#define __GRASS_FACTORY_H__

#include "CreatureFactory.h"
#include "Map\LargeMap.h"
#include "Map\GameMap.h"
#include "Map\GameMapSprite.h"

class GrassFactory : public CreatureFactory
{
	public:
		GrassFactory() {};
		GrassFactory(int _id) { id = _id; };

		virtual void createCreature();
};

#endif // !__GRASS_FACTORY_H__
