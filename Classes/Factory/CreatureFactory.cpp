#include "CreatureFactory.h"
#include "Animal.h"

CreatureFactory::CreatureFactory(int _id) { id = _id; }

CreatureFactory::~CreatureFactory() {}

EventListenerTouchOneByOne* CreatureFactory::createListener() {
	auto listener = EventListenerTouchOneByOne::create();
	listener->setSwallowTouches(true);

	listener->onTouchBegan = [](Touch* touch, Event* event){
		auto target = static_cast<Animal*>(event->getCurrentTarget());

		if (target->isSelected) {
			log("Moving ...");

			target->stopAllActions();
			target->runAction(MoveTo::create(2.0f, touch->getLocation()));
			target->isSelected = false;

			return true;
		}
		else {
			Point locationInNode = target->convertToNodeSpace(touch->getLocation());
			Size s = target->getContentSize();
			Rect rect = Rect(0, 0, s.width, s.height);

			if (rect.containsPoint(locationInNode))
			{
				log("sprite began... x = %f, y = %f", locationInNode.x, locationInNode.y);
				target->isSelected = true;

				return true;
			}

			return false;
		}
	};

	return listener;
}