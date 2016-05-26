#ifndef __SHEEP_FACTORY_H__
#define __SHEEP_FACTORY_H__

#include "CreatureFactory.h"

class SheepFactory : public CreatureFactory
{
	public:
		SheepFactory() {};
		SheepFactory(int _id) { id = _id; };

		virtual void createCreature();
};

#endif // !__SHEEP_FACTORY_H__
