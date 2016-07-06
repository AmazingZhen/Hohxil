#ifndef _ANIMAL_PANEL_H
#define _ANIMAL_PANEL_H

#include "cocos2d.h"
#include "DragItemImage.h"

class DragLayer : public Layer {
private:
	float width, height, padding;
	Sprite* background;
	Vector<DragItemImage*> dragItems;
	void initLayer();
	void scaleBackground();
public:
	Sprite* getBackground();
	float getWidth();
	float getHeight();
	void addDragItem(DragItemImage* dragSprite);
	//static DragLayer* create(DragItemImage* item1, ...);
	static DragLayer* create();
};

#endif