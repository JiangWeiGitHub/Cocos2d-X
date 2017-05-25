#ifndef __KEYMANAGER_H__
#define __KEYMANAGER_H__

#pragma once  

#include "iostream"
#include "cocos2d.h"

#include "./KeyboardState.h"
#include "./KeyTop.h"
#include "./KeyBottom.h"
#include "./KeyLeft.h"
#include "./KeyRight.h"
#include "./KeyStop.h"

namespace jiangweigithub {

  class KeyManager
  {
  public:  
    KeyManager(std::string name);
    ~KeyManager();
  
    void setState(KeyboardState* state);
    KeyboardState* getStateTop();
    KeyboardState* getStateBottom();
    KeyboardState* getStateLeft();
    KeyboardState* getStateRight();
    KeyboardState* getStateStop();

    void pressTop(cocos2d::Sprite* sprite, float& x, float& y);
    void pressBottom(cocos2d::Sprite* sprite, float& x, float& y);
    void pressLeft(cocos2d::Sprite* sprite, float& x, float& y);
    void pressRight(cocos2d::Sprite* sprite, float& x, float& y);

  private:  
    KeyboardState* _state;
    KeyboardState* _stateTop;
    KeyboardState* _stateBottom;
    KeyboardState* _stateLeft;
    KeyboardState* _stateRight;
    KeyboardState* _stateStop; 
  };

}

#endif // __KEYMANAGER_H__
