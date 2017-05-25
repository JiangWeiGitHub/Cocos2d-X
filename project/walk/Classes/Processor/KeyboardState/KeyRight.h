#ifndef __KEYRIGHT_H__
#define __KEYRIGHT_H__

#include "iostream"
#include "cocos2d.h"

#include "./KeyboardState.h"

namespace jiangweigithub {

  class KeyManager;

  class KeyRight : public KeyboardState
  {
  public:
    KeyRight(KeyManager* km);
    ~KeyRight();
    void pressTop(cocos2d::Sprite* sprite, float& x, float& y);
    void pressBottom(cocos2d::Sprite* sprite, float& x, float& y);
    void pressLeft(cocos2d::Sprite* sprite, float& x, float& y);
    void pressRight(cocos2d::Sprite* sprite, float& x, float& y);
  private:
    KeyManager* keyManager;
  };

}

#endif // __KEYRIGHT_H__
