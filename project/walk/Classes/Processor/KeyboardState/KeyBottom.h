#ifndef __KEYBOTTOM_H__
#define __KEYBOTTOM_H__

#include "iostream"
#include "cocos2d.h"

#include "./KeyboardState.h"

namespace jiangweigithub {

  class KeyManager;

  class KeyBottom : public KeyboardState
  {
  public:
    KeyBottom(KeyManager* km);
    ~KeyBottom();
    void pressTop(cocos2d::Sprite* sprite, float& x, float& y);
    void pressBottom(cocos2d::Sprite* sprite, float& x, float& y);
    void pressLeft(cocos2d::Sprite* sprite, float& x, float& y);
    void pressRight(cocos2d::Sprite* sprite, float& x, float& y);
  private:
    KeyManager* keyManager;
  };

}

#endif // __KEYBOTTOM_H__
