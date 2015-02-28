#pragma once
#include "cocos2d.h"
USING_NS_CC;
class SpotLight :
	public CCSprite
{
public:
	virtual bool init(CCRenderTexture* render,float radius,ccColor4B color);
	static SpotLight* create(CCRenderTexture* render,float radius,ccColor4B color);

	//virtual void draw();
	void update(float dt);
private:
	CCRenderTexture* m_render;
	float m_radius;
	ccColor4B m_color;

	GLfloat * m_vertexs;
	GLfloat * m_coords;
	ccColor4B* m_colors;
};

