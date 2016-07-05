#ifndef __GRASS_FACTORY_H__
#define __GRASS_FACTORY_H__

#include "CreatureFactory.h"
#include "LargeMap.h"
#include "GameMap.h"
#include "GameMapSprite.h"

class GrassFactory : public CreatureFactory
{
	public:
    
		virtual void createCreature();
};

#endif // !__GRASS_FACTORY_H__
