#include "./Loading.h"

namespace jiangweigithub {

  bool LoadingLayer::init()
  {
    if ( !Layer::init() )
    {
      return false;
    }

    // auto loadingSprite = LoadingSprite::getLoadingSprite();
    // auto loadingTitle = LoadingSprite::getLoadingTitle();

    // auto spriteSize = loadingSprite->getContentSize();
    // auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    // loadingSprite->setPosition(cocos2d::Vec2((visibleSize.width - spriteSize.width) / 2, (visibleSize.height - spriteSize.height) / 2));
    // loadingTitle->setPosition(cocos2d::Vec2((visibleSize.width - spriteSize.width) / 2, (visibleSize.height - spriteSize.height) / 2 + 60));

    // this->addChild(loadingSprite);
    // this->addChild(loadingTitle);
    Role::Role* role = new Role::Role();
    std::vector<cocos2d::Rect> vec;
    vec.push_back(cocos2d::Rect(180,0,30,50));
    vec.push_back(cocos2d::Rect(210,0,30,50));
    vec.push_back(cocos2d::Rect(240,0,30,50));
    vec.push_back(cocos2d::Rect(210,0,30,50));
    cocos2d::Animation* walkRight = role->getAnimationRight(vec);

    return true;
  }

  cocos2d::Layer* LoadingLayer::getLoadingLayer()
  {
    auto tmp = LoadingLayer::create();

    return tmp;
  }

}