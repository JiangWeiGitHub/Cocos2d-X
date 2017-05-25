#ifndef __KEYLEFT_H__
#define __KEYLEFT_H__

#include "iostream"
#include "cocos2d.h"

#include "./KeyboardState.h"

namespace jiangweigithub {

  class KeyManager;

  class KeyLeft : public KeyboardState
  {
  public:
    KeyLeft(KeyManager* km);
    ~KeyLeft();
    void pressTop(cocos2d::Sprite* sprite, float& x, float& y);
    void pressBottom(cocos2d::Sprite* sprite, float& x, float& y);
    void pressLeft(cocos2d::Sprite* sprite, float& x, float& y);
    void pressRight(cocos2d::Sprite* sprite, float& x, float& y);
  private:
    KeyManager* keyManager;
  };

}

#endif // __KEYLEFT_H__
