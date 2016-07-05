#ifndef  _GAME_MAP_SPRITE_H_
#define  _GAME_MAP_SPRITE_H_

#include "cocos2d.h"

USING_NS_CC;

class LargeMap;
class GameMap;

class GameMapSprite : public Sprite
{
public:
	static GameMapSprite* create(const std::string& filename);

	void updateGameMap();

	Scene* getGameMap() { return gameMap; }

private:
	void initGameMap();

	void addCallbackFunc();

	Scene* gameMap;
};

#endif // _GAME_MAP_SPRITE_H_