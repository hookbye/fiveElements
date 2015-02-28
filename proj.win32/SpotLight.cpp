#include "SpotLight.h"

const float SEGS = 45;

bool SpotLight::init(CCRenderTexture* render,float radius,ccColor4B color)
{
	do
	{
		CC_BREAK_IF(!CCSprite::init());
		CCSize winSize = CCDirector::sharedDirector()->getWinSize();
		setPosition( ccp( winSize.width / 2, winSize.height / 2 ) );
		m_render = render;
		m_radius = radius;
		m_color = color;

		m_vertexs = (GLfloat*)malloc(sizeof(GLfloat)*2*SEGS);
		m_colors = (ccColor4B*)malloc(sizeof(ccColor4B)*SEGS);
		m_coords = (GLfloat*)malloc(sizeof(GLfloat)*2*SEGS);
		 
		this->scheduleUpdate();
		return true;
	}while(0);
	return false;
}
SpotLight* SpotLight::create(CCRenderTexture* render,float radius,ccColor4B color)
{
	SpotLight* spotlight = new SpotLight();
	if (spotlight &&spotlight->init(render,radius,color))
	{
		spotlight->autorelease();
		return spotlight;
	}
	CC_SAFE_DELETE(spotlight);
	return NULL;
}

//void SpotLight::draw()
//{
//	CCSprite::draw();
//	CC_NODE_DRAW_SETUP();
//	memset(m_vertexs,0,sizeof(GLfloat)*2*SEGS);
//	memset(m_coords,0,sizeof(GLfloat)*2*SEGS);
//
//	m_colors[0] = ccc4(0,0,0,255);
//	for(int i=1;i<SEGS;i++)
//	{
//		m_colors[i] = ccc4(0,0,0,0);
//	}
//
//	
//	CCLog("pos,%f,%f: ",getPositionX(),getPositionY());
//	m_vertexs[0] = getPositionX();
//	m_vertexs[1] = getPositionY();
//
//	m_coords[0] = getPositionX();
//	m_coords[1] = getContentSize().height - getPositionY();
//
//	const float coef = 2.0f* (float)M_PI/(SEGS-2);
//	float x = m_radius* cosf(2*coef)+getPositionX();
//	float y = m_radius* sinf(2*coef)+getPositionY();
//	CCLog("%f,%f: ",x,y);
//	for (int i = 1;i<=SEGS;i++)
//	{
//		float rads = i*coef ;
//		float x = m_radius* cosf(rads)+getPositionX();
//		float y = m_radius* sinf(rads)+getPositionY();
//
//		m_vertexs[2*i] = x;
//		m_vertexs[2*i+1] = y;
//		 
//		m_coords[2*i] = x;
//		m_coords[2*i+1] = getContentSize().height - y;
//	}
//
//	m_render->clear(m_color.r/255.0f,
//		m_color.g/255.0f,m_color.b/255.0f,
//		m_color.a/255.0f);
//	m_render->begin();
//	ccGLBindTexture2D((GLuint)m_render);
//	ccGLBlendFunc(GL_ZERO,GL_ONE_MINUS_SRC_ALPHA);
//	ccGLEnableVertexAttribs(kCCVertexAttribFlag_PosColorTex);
//
//	glVertexAttribPointer(kCCVertexAttrib_Position,2,GL_FLOAT,GL_FALSE,0,m_vertexs);
//	glVertexAttribPointer(kCCVertexAttrib_TexCoords,2,GL_FLOAT,GL_FALSE,0,m_coords);
//	glVertexAttribPointer(kCCVertexAttrib_Color,4,GL_UNSIGNED_BYTE,GL_TRUE,0,m_colors);
//	 
//	glDrawArrays(GL_TRIANGLE_FAN,0,SEGS);
//	m_render->end();
//	 
//}

void SpotLight::update(float dt)
{
	CC_NODE_DRAW_SETUP();
	memset(m_vertexs,0,sizeof(GLfloat)*2*SEGS);
	memset(m_coords,0,sizeof(GLfloat)*2*SEGS);

	m_colors[0] = ccc4(0,0,0,255);
	for(int i=1;i<SEGS;i++)
	{
		m_colors[i] = ccc4(0,0,0,0);
	}

	
	CCLog("pos,%f,%f: ",getPositionX(),getPositionY());
	m_vertexs[0] = getPositionX();
	m_vertexs[1] = getPositionY();

	m_coords[0] = getPositionX();
	m_coords[1] = getContentSize().height - getPositionY();

	const float coef = 2.0f* (float)M_PI/(SEGS-2);
	float x = m_radius* cosf(2*coef)+getPositionX();
	float y = m_radius* sinf(2*coef)+getPositionY();
	CCLog("%f,%f: ",x,y);
	for (int i = 1;i<=SEGS;i++)
	{
		float rads = i*coef ;
		float x = m_radius* cosf(rads)+getPositionX();
		float y = m_radius* sinf(rads)+getPositionY();

		m_vertexs[2*i] = x;
		m_vertexs[2*i+1] = y;
		 
		m_coords[2*i] = x;
		m_coords[2*i+1] = getContentSize().height - y;
	}

	m_render->clear(m_color.r/255.0f,
		m_color.g/255.0f,m_color.b/255.0f,
		m_color.a/255.0f);
	m_render->begin();
	ccGLBindTexture2D((GLuint)m_render);
	ccGLBlendFunc(GL_ZERO,GL_ONE_MINUS_SRC_ALPHA);
	ccGLEnableVertexAttribs(kCCVertexAttribFlag_PosColorTex);

	glVertexAttribPointer(kCCVertexAttrib_Position,2,GL_FLOAT,GL_FALSE,0,m_vertexs);
	glVertexAttribPointer(kCCVertexAttrib_TexCoords,2,GL_FLOAT,GL_FALSE,0,m_coords);
	glVertexAttribPointer(kCCVertexAttrib_Color,4,GL_UNSIGNED_BYTE,GL_TRUE,0,m_colors);
	 
	glDrawArrays(GL_TRIANGLE_FAN,0,SEGS);
	m_render->end();
}