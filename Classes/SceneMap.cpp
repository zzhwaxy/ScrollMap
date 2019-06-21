#include "SceneMap.h"
#include "math.h"
#define SCREEN_HEIGHT 1200
#define SCREEN_WIDTH  132
USING_NS_CC;
Scene* SceneMap::scene()
{
	Scene *scene = Scene::create();
	auto *layer = SceneMap::create();
	scene->addChild(layer);
	return scene;
}

bool SceneMap::init()
{
	if (!cocos2d::Layer::init())
	{
		return false;
	}
	
	s = cocos2d::Director::getInstance()->getWinSize();
	m_map1 = Sprite::create("circle.jpg");
	m_map2 = Sprite::create("circle.jpg");
	m_map3 = Sprite::create("circle.jpg");
	
	m_map1->setAnchorPoint(ccp(0, 0));
	m_map2->setAnchorPoint(ccp(0, 0));
	m_map3->setAnchorPoint(ccp(0, 0));

	m_map1->setPosition(ccp(0, 0));
	
	CCSize visableSize = CCSizeMake(SCREEN_WIDTH, SCREEN_HEIGHT); 
	CCSize mysize = CCSizeMake(SCREEN_WIDTH,SCREEN_HEIGHT); 
										  
	CCLayerColor* scrollLayer = CCLayerColor::create(ccc4(255, 255, 255, 255));
	scrollLayer->setContentSize(mysize);

	scrollLayer->addChild(m_map1);
	scrollLayer->addChild(m_map2);
	scrollLayer->addChild(m_map3);

	ScrollView* scrollView = ScrollView::create();
	this->addChild(scrollView, 0);

	
	scrollView->setContainer(scrollLayer); 
	scrollView->setViewSize(visableSize); 
	scrollView->setBounceable(true); 
	scrollView->setDirection(ScrollView::Direction::VERTICAL);
	
	scrollView->setContentSize(cocos2d::Size(SCREEN_WIDTH,SCREEN_HEIGHT*10));
	scrollView->setDelegate(this);
	return true;
}
void SceneMap::scrollViewDidScroll(ScrollView* view)
{

	float offset = view->getContentOffset().y;
	if (offset-offset_save <0)
	{
		if ((int)offset / SCREEN_HEIGHT % 3 == -2 && offset != 0)
		{
			m_map1->setPosition(ccp(0,m_map3->getPosition().y + SCREEN_HEIGHT));
		}
		if ((int)offset / SCREEN_HEIGHT % 3 == 0 && offset != 0)
		{
			m_map2->setPosition(ccp(0,m_map1->getPosition().y + SCREEN_HEIGHT ));
		}
		if ((int)offset / SCREEN_HEIGHT % 3 == -1 && offset != 0)
		{
			m_map3->setPosition(ccp(0,m_map2->getPosition().y + SCREEN_HEIGHT));
		}
	}
	if (offset - offset_save > 0)
	{
		
		if ((int)offset / SCREEN_HEIGHT % 3 == -2 && offset != 0)
		{
			m_map3->setPosition(ccp(0, m_map1->getPosition().y - SCREEN_HEIGHT));
		}
		if ((int)offset / SCREEN_HEIGHT % 3 == 0 && offset != 0)
		{
			m_map1->setPosition(ccp(0, m_map2->getPosition().y - SCREEN_HEIGHT));
		}
		if ((int)offset / SCREEN_HEIGHT % 3 == -1 && offset != 0)
		{
			m_map2->setPosition(ccp(0, m_map3->getPosition().y - SCREEN_HEIGHT));
		}
	}
	offset_save = offset;
}
void SceneMap::scrollViewDidZoom(ScrollView* view)
{
}
