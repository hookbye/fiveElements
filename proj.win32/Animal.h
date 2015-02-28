#pragma once
#include "cocos2d.h"
USING_NS_CC;
class Animal :
	public CCSprite
{
public:
	virtual bool init();

	void initAnimations();
	enum animalSt {
		ANI_IDLE,
		ANI_RUN,
	};
	void setStatus(animalSt st);
	int getStatus(){return status;}
	CREATE_FUNC(Animal);
private:
	animalSt status;

};

