#include "./LoadingLayer.h"

namespace jiangweigithub {

  bool LoadingLayer::init()
  {
    if ( !Layer::init() )
    {
      return false;
    }

    auto loadingSprite = LoadingSprite::getLoadingSprite();
    auto loadingTitle = LoadingSprite::getLoadingTitle();

    auto spriteSize = loadingSprite->getContentSize();
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    loadingSprite->setPosition(cocos2d::Vec2((visibleSize.width - spriteSize.width) / 2, (visibleSize.height - spriteSize.height) / 2));
    loadingTitle->setPosition(cocos2d::Vec2((visibleSize.width - spriteSize.width) / 2, (visibleSize.height - spriteSize.height) / 2 + 60));

    this->addChild(loadingSprite);
    this->addChild(loadingTitle);

    return true;
  }

  cocos2d::Layer* LoadingLayer::getLoadingLayer()
  {
    auto tmp = LoadingLayer::create();

    return tmp;
  }

}