#include "./Loading.h"

namespace jiangweigithub {

  bool LoadingLayer::init()
  {
    if ( !Layer::init() )
    {
      return false;
    }

    jiangweigithub::Role* role = new jiangweigithub::Role();
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