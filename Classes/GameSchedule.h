#ifndef _GAME_SCHEDULE_
#define _GAME_SCHEDULE_

#include "cocos2d.h"

#define UPDATE_INTERVAL 0.1
#define MAX_UPDATE_INTERVAL 40

USING_NS_CC;

class GameSchedule : public Ref
{
public:
    static GameSchedule* getInstance();
    void start();
    void end();
    void pause();
	void resume();
	int getSpeed();
	void setSpeed(int speed);
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
	static int updateIntervalTimes;
	static int count;
	static int speed;
};

#endif // _GAME_SCHEDULE_