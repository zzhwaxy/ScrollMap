#ifndef _SceneMap_H__
#define _SceneMap_H__

#include "cocos2d.h"
#include "cocos-ext.h"
USING_NS_CC;
using namespace cocos2d::extension;


class SceneMap: public cocos2d::Layer,public ScrollViewDelegate
{
public:
	virtual bool init();
	static cocos2d::Scene* scene();
	CREATE_FUNC(SceneMap);

protected:
	cocos2d::CCSize s;
	
    cocos2d::Sprite*  m_map1;
	cocos2d::Sprite* m_map2;
	cocos2d::Sprite* m_map3;
	

private:
	cocos2d::Vec2 startPos;
	virtual void scrollViewDidScroll(ScrollView* view); 
	virtual void scrollViewDidZoom(ScrollView* view);
	float offset_save = 0;
};
#endif
