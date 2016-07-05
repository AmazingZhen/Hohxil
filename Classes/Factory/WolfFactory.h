#ifndef __WOLF_FACTORY_H__
#define __WOLF_FACTORY_H__

#include "CreatureFactory.h"

class WolfFactory : public CreatureFactory
{
	public:
		WolfFactory() {};
		WolfFactory(int _id) { id = _id; };

		virtual void createCreature();

		// added by XuYongzhe
		// add a wolf in gameMap
		virtual void createWolf(Scene* gameScene, const Vec2 & pos);

};

#endif // !__WOLF_FACTORY_H__