#ifndef _GAME_MAP_H_
#define _GAME_MAP_H_

#include "cocos2d.h"

class GameMap : public cocos2d::Layer
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();

	// a selector callback
	void menuCloseCallback(cocos2d::Ref* pSender);
	void menuPauseCallback(cocos2d::Ref* pSender);
	void menuIntervalCallback(cocos2d::Ref* pSender);

	// update the speed button
	void updateMenuIntervalButton();
	// implement the "static create()" method manually
	CREATE_FUNC(GameMap);

private:
	void createMenu();
	void createMap(); 
	void createDragMenu();  
	void createTimeLabel();
	void updateTime(float dt);

private:
	cocos2d::Label* timeLabel;

};

#endif // _GAME_MAP_H_
