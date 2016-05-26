#ifndef __WOLF_FACTORY_H__
#define __WOLF_FACTORY_H__

#include "CreatureFactory.h"

class WolfFactory : public CreatureFactory
{
	public:
		WolfFactory() {};
		WolfFactory(int _id) { id = _id; };

		virtual void createCreature();

};

#endif // !__WOLF_FACTORY_H__