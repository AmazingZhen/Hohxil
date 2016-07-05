#ifndef _GAMEPAUSE_H_  
#define _GAMEPAUSE_H_

#include "cocos2d.h"  

USING_NS_CC;
class GamePause : public cocos2d::Layer
{
public:
	virtual bool init();
	static cocos2d::Scene* scene(RenderTexture* sqr);
	CREATE_FUNC(GamePause);
	//¼ÌÐøÓÎÏ·  
	void menuContinueCallback(Ref* pSender);

private:

};


#endif // _GAME_PAUSE_H_