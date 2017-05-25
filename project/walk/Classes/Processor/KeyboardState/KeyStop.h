#ifndef __KEYSTOP_H__
#define __KEYSTOP_H__

#include "iostream"
#include "cocos2d.h"

#include "./KeyboardState.h"

namespace jiangweigithub {

  class KeyStop : public KeyboardState
  {
  public:
    KeyStop(KeyManager* km);
    ~KeyStop();
    void pressTop(cocos2d::Sprite* sprite, float& x, float& y);
    void pressBottom(cocos2d::Sprite* sprite, float& x, float& y);
    void pressLeft(cocos2d::Sprite* sprite, float& x, float& y);
    void pressRight(cocos2d::Sprite* sprite, float& x, float& y);

  private:
    KeyManager* keyManager;
  };

}

#endif // __KEYSTOP_H__
