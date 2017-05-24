#include "./Home.h"

namespace jiangweigithub {

  cocos2d::Scene* Home::getHomeScene()
  {
    auto tmp = Home::create();

    return tmp;
  }

  bool Home::init()
  {
    if(!cocos2d::Scene::initWithPhysics()) 
    {
      return false;
    }

    // this->getPhysicsWorld()->setDebugDrawMask(cocos2d::PhysicsWorld::DEBUGDRAW_ALL);

    auto tmp = HomeLayer::getHomeLayer();
    auto talkFrame = TalkFrame::getTalkFrame();

    if(Director::getChapter() == CHAPTER::HOME)
    {

    }

    this->addChild(tmp, 0);
    this->addChild(talkFrame, 1);

    return true;
  }

}