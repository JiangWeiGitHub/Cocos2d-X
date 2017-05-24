#ifndef __LOADINGLAYER_H__
#define __LOADINGLAYER_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../Sprite/Loading/LoadingSprite.h"

namespace jiangweigithub {

  class LoadingLayer : public cocos2d::Layer
  {
  public:
    virtual bool init();

    static cocos2d::Layer* getLoadingLayer();

    CREATE_FUNC(LoadingLayer);
  };

}

#endif // __LOADINGLAYER_H__