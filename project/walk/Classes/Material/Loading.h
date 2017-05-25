#ifndef __LOADINGSPRITE_H__
#define __LOADINGSPRITE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

namespace jiangweigithub {

  class LoadingSprite
  {
  public:
    static cocos2d::Sprite* getLoadingSprite();
    static cocos2d::Label* getLoadingTitle();

    static void setLoadingTitle(std::string name);

    static std::string name;    
  };
  
}
#endif // __LOADINGSPRITE_H__