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
	// ���¿�ʼ  
	void menuRestartCallback(Ref* pSender);
	// ������Ϸ
	void menuEndCallback(Ref* pSender);

private:
};

#endif

