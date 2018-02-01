#include "./Loading.h"

namespace jiangweigithub {

  std::string LoadingSprite::name = "Loading...";

  cocos2d::Sprite* LoadingSprite::getLoadingSprite()
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage("sabin.png");

    // right
    cocos2d::SpriteFrame* frame1 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(180,0,30,50));
    cocos2d::SpriteFrame* frame2 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));
    cocos2d::SpriteFrame* frame3 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(240,0,30,50));
    cocos2d::SpriteFrame* frame4 = cocos2d::SpriteFrame::createWithTexture(textTure, cocos2d::Rect(210,0,30,50));

    cocos2d::Vector<cocos2d::SpriteFrame*> right;
    right.pushBack(frame1);
    right.pushBack(frame2);
    right.pushBack(frame3);
    right.pushBack(frame4);

    auto loadingSprite = cocos2d::Sprite::createWithSpriteFrame(frame1);

    auto animationRight = cocos2d::Animation::createWithSpriteFrames(right,0.2f);

    loadingSprite->runAction(cocos2d::RepeatForever::create(cocos2d::Animate::create(animationRight)));

    return loadingSprite;
  }

  cocos2d::Label* LoadingSprite::getLoadingTitle()
  {
    auto loadingTitle = cocos2d::Label::createWithTTF(name, "fonts/MSYHBD.TTF", 24);
    loadingTitle->enableBold();
    loadingTitle->setAdditionalKerning(1);

    return loadingTitle;
  }

  void LoadingSprite::setLoadingTitle(std::string name)
  {
    LoadingSprite::getLoadingTitle()->setString(name);
    LoadingSprite::getLoadingTitle()->updateContent();
  }

}