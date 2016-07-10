#ifndef _INITIAL_LAYER_H_
#define _INITIAL_LAYER_H_

#include "cocos2d.h"
#include <string>
using namespace std;
USING_NS_CC;

class InitialLayer : public cocos2d::Layer
{
public:
	// there's no 'id' in cpp, so we recommend returning the class instance pointer
	static cocos2d::Scene* createScene();

	// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
	virtual bool init();

	// a selector callback
	void menuExitCallback(cocos2d::Ref* pSender);

	void menuStartCallBack(cocos2d::Ref* pSender);

	void menuSettingCallBack(cocos2d::Ref* pSender);

	void okCallBack(cocos2d::Ref* pSender);
	// implement the "static create()" method manually
	CREATE_FUNC(InitialLayer);

private:
	Sprite* helpScene;
	MenuItemImage* okItem;
};

#endif // _INITIAL_LAYER_H_
