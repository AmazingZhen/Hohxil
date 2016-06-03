#include "GamePause.h"
#include "GameSchedule.h"

Scene* GamePause::scene(RenderTexture* sqr)
{
	Scene *scene = Scene::create();
	GamePause *layer = GamePause::create();
	scene->addChild(layer, 1);
	//增加部分：使用Game界面中截图的sqr纹理图片创建Sprite  
	//并将Sprite添加到GamePause场景层中  
	//得到窗口的大小  
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite *back_spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	back_spr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2)); //放置位置,这个相对于中心位置。  
	back_spr->setFlipY(true);            //翻转，因为UI坐标和OpenGL坐标不同  
	back_spr->setColor(Color3B::GRAY); //图片颜色变灰色  
	scene->addChild(back_spr);
	return scene;
}

bool GamePause::init()
{

	if (!Layer::init())
	{
		return false;
	}
	//得到窗口的大小  
	Size visibleSize = Director::sharedDirector()->getVisibleSize();
	//原点坐标  
	Point origin = Director::sharedDirector()->getVisibleOrigin();

	//继续游戏按钮  
	MenuItemImage *pContinueItem = MenuItemImage::create(
		"UI/ResumeNormal.png",
		"UI/ResumeSelected.png",
		this,
		menu_selector(GamePause::menuContinueCallback));

	pContinueItem->setPosition(Vec2(origin.x + visibleSize.width - pContinueItem->getContentSize().width / 2,
		origin.y + visibleSize.height - pContinueItem->getContentSize().height / 2));


	Menu* pMenu = Menu::create(pContinueItem, NULL);
	pMenu->setPosition(Vec2::ZERO);
	this->addChild(pMenu, 2);

	return true;
}
void GamePause::menuContinueCallback(Ref* pSender)
{
	GameSchedule::getInstance()->resume();
	Director::getInstance()->popScene();

}