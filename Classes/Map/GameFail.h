#ifndef _GAMEFAIL_H_  
#define _GAMEFAIL_H_

#include "cocos2d.h" 
USING_NS_CC;

class GameFail : public Layer
{
public:
	virtual bool init();
	static cocos2d::Scene* createScene();

	CREATE_FUNC(GameFail);
	// 重新开始  
	void menuRestartCallback(Ref* pSender);
	// 结束游戏
	void menuEndCallback(Ref* pSender);

private:
};

#endif

