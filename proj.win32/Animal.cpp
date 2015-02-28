#include "Animal.h"


bool Animal::init()
{
	do
	{
		CC_BREAK_IF(!CCSprite::initWithFile("run_01.png"));
		setContentSize(CCSizeMake(20,20));
		initAnimations();
		return true;
	}while(0);
	return false;
}

void Animal::initAnimations()
{
	CCSpriteFrame* frame;
	//CCString* fname = CCString::createWithFormat(,);
	char fName[128];
	CCRect fRect = CCRectMake(0,0,180,180);
	CCArray* frames = CCArray::create();
	frames->retain();
	for(int i=0;i<2;i++)
	{
		sprintf(fName,"run_%02d.png",i+1);
		frame = CCSpriteFrame::create(fName,fRect);
		frames->addObject(frame);
	}
	CCAnimation * animation = CCAnimation::createWithSpriteFrames(frames,0.5);
	CCAnimate* animate = CCAnimate::create(animation);
	runAction(CCRepeatForever::create(animate));

}
void Animal::setStatus(animalSt st)
{
	switch (st)
	{
	case Animal::ANI_IDLE:
		break;
	case Animal::ANI_RUN:
		break;
	default:
		break;
	}
}