#include "GamePause.h"
#include "GameSchedule.h"

Scene* GamePause::scene(RenderTexture* sqr)
{
	Scene *scene = Scene::create();
	GamePause *layer = GamePause::create();
	scene->addChild(layer, 1);
	//���Ӳ��֣�ʹ��Game�����н�ͼ��sqr����ͼƬ����Sprite  
	//����Sprite��ӵ�GamePause��������  
	//�õ����ڵĴ�С  
	Size visibleSize = Director::getInstance()->getVisibleSize();
	Sprite *back_spr = Sprite::createWithTexture(sqr->getSprite()->getTexture());
	back_spr->setPosition(Vec2(visibleSize.width / 2, visibleSize.height / 2)); //����λ��,������������λ�á�  
	back_spr->setFlipY(true);            //��ת����ΪUI�����OpenGL���겻ͬ  
	back_spr->setColor(Color3B::GRAY); //ͼƬ��ɫ���ɫ  
	scene->addChild(back_spr);
	return scene;
}

bool GamePause::init()
{

	if (!Layer::init())
	{
		return false;
	}
	//�õ����ڵĴ�С  
	Size visibleSize = Director::sharedDirector()->getVisibleSize();
	//ԭ������  
	Point origin = Director::sharedDirector()->getVisibleOrigin();

	//������Ϸ��ť  
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