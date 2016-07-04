#ifndef _GAMESUCCESS_H_  
#define _GAMESUCCESS_H_

#include "cocos2d.h" 
USING_NS_CC;

class GameSuccess : public Layer
{
public:
	virtual bool init();
	static cocos2d::Scene* createScene();

	CREATE_FUNC(GameSuccess);
	// 重新开始  
	void menuRestartCallback(Ref* pSender);
	// 结束游戏
	void menuEndCallback(Ref* pSender);

private:
};

#endif

