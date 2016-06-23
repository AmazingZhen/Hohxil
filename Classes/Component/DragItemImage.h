#ifndef DRAG_ANIMAL_SPRITE_H
#define DRAG_ANIMAL_SPRITE_H

#include "cocos2d.h"
#include "Map\GameMap.h"
#include "Model\Creatures\Creature.h"

using namespace std;

USING_NS_CC;

class DragItemImage : public MenuItemImage
{
private:
	bool isDragged;
	Point originPos;	// the original position when this item is added in menu
	GameMap *gameMap;
	CreatureSpecies species;
	int sum;   // card number
	void initMouseLintener();
	DragItemImage(GameMap* gameMap, CreatureSpecies spec);
	bool onTouchBegan(Touch* touch, Event* event);
	void onTouchMoved(Touch* touch, Event* event);
	void onTouchEnded(Touch* touch, Event* event);
public:
	void initOriginalPoint(Point &p);
	Point getOriginalPoint();
	static DragItemImage* create(const string& normalImage, const string& selectedImage, const string& disabledImage, GameMap* gameMap, CreatureSpecies spec);
};

#endif