#pragma once
#include "cocos2d.h"
#include "Animal.h"
#include "SpotLight.h"
USING_NS_CC;
class GameLayer :
	public CCLayer
{
public:
	static CCScene* scene();

	virtual bool init();

	virtual bool ccTouchBegan(CCTouch* ptouch ,CCEvent* pevent);
	virtual void ccTouchMoved(CCTouch* ptouch ,CCEvent* pevent);
	virtual void ccTouchEnded(CCTouch* ptouch ,CCEvent* pevent);
	
	CREATE_FUNC(GameLayer);

private:
	Animal* player;
	SpotLight* spotlight;
};

