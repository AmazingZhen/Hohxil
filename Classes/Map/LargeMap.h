#ifndef _LARGE_MAP_H_
#define _LARGE_MAP_H_

#include "cocos2d.h"
#include "GameMapSprite.h"

#define MAP_NUM 10

int randomNum(int min, int max);
double randomNum(double min, double max);

class LargeMap : public cocos2d::Layer
{
public:
	// Singleton pattern.
	static cocos2d::Scene* getInstance();

	GameMapSprite* getGameMapSpriteById(int mapId);

	int getMapSize() { return maps.size(); }

	// update the speed button
	void updateMenuIntervalButton();


private:
	virtual bool init();

	// implement the "static create()" method manually
	CREATE_FUNC(LargeMap);

	static cocos2d::Scene* createScene();

	void menuCloseCallback(cocos2d::Ref* pSender);
	void menuPauseCallback(cocos2d::Ref* pSender);
	void menuIntervalCallback(cocos2d::Ref* pSender);

	void createMenu();

	GameMapSprite* createMap();
	void createMaps(int mapNum);

private:
	static cocos2d::Vector<GameMapSprite*> maps;
	static cocos2d::Scene* largeMap;
};

#endif //_LARGEMAP_SCENE_H_
