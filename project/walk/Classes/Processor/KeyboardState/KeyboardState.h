#ifndef __KEYBOARDSTATE_H__
#define __KEYBOARDSTATE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../Obstacle/Obstacle.h"

// top bottom left right stop -> five states

namespace jiangweigithub {

  class KeyManager;

  class KeyboardState
  {
  public:
    KeyboardState();
    ~KeyboardState();

    virtual void pressTop(cocos2d::Sprite* sprite, float& x, float& y) {};
    virtual void pressBottom(cocos2d::Sprite* sprite, float& x, float& y) {};
    virtual void pressLeft(cocos2d::Sprite* sprite, float& x, float& y) {};
    virtual void pressRight(cocos2d::Sprite* sprite, float& x, float& y) {};
    
    Obstacle* obstacle;
  };

}

#endif // __KEYBOARDSTATE_H__
