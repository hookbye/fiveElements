#include "GameLayer.h"


CCScene* GameLayer::scene()
{
	CCScene* scene = CCScene::create();
	GameLayer* layer = GameLayer::create();
	scene->addChild(layer);
	return scene;
}

bool GameLayer::init()
{
	do{
		CC_BREAK_IF(!CCLayer::init());
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();

		

		CCSprite* bg = CCSprite::create("HelloWorld.png");
		bg->setAnchorPoint(ccp(0,0));
		addChild(bg);
		player = Animal::create();
		player->setPosition(ccp(winSize.width/2,winSize.height/2));
		addChild(player);
		
		CCRenderTexture* render = CCRenderTexture::create(winSize.width,winSize.height);
		render->setPosition(ccp(winSize.width/2,winSize.height/2));
		ccBlendFunc blend = {GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA};
		render->getSprite()->setBlendFunc(blend);
		addChild(render);
		spotlight = SpotLight::create(render,90,ccc4(0,0,0,240));
		//spotlight->setPosition(ccp(0,0));//(ccp(winSize.width/2,winSize.height/2));
		addChild(spotlight);

		this->setTouchEnabled(true);
		this->setTouchMode(kCCTouchesOneByOne);
		return true;
	}while(0);
	
	return false;
}

bool GameLayer::ccTouchBegan(CCTouch* ptouch ,CCEvent* pevent)
{
	return true;
}
void GameLayer::ccTouchMoved(CCTouch* ptouch ,CCEvent* pevent)
{
	CCPoint pos = ptouch->getLocation();
	CCLog("%f,%f: ",pos.x,pos.y);
	spotlight->setPosition(pos);
}
void GameLayer::ccTouchEnded(CCTouch* ptouch ,CCEvent* pevent)
{
}