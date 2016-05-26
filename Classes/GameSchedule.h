#ifndef _GAME_SCHEDULE_
#define _GAME_SCHEDULE_

#include "cocos2d.h"

#define UPDATE_INTERVAL 4.0

USING_NS_CC;

class GameSchedule : public Ref
{
public:
    static GameSchedule* getInstance();
    void start();
    void end();
    void pause();
    void resume();
private:
    virtual void onExit();
    ~GameSchedule();
    void globalUpdate(float time);
	bool init();

	// --------- Game logic ---------

	void sheepMove();
	void wolfMove();

	void sheepEatGrass();
	void wolfEatSheep();

	// ------------------------------


	static GameSchedule* gameSchedule;
	static bool isPaused;
};

#endif // _GAME_SCHEDULE_