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
	// ���¿�ʼ  
	void menuRestartCallback(Ref* pSender);
	// ������Ϸ
	void menuEndCallback(Ref* pSender);

private:
};

#endif

