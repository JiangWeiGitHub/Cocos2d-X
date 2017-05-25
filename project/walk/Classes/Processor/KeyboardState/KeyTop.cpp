#include "./KeyTop.h"
#include "./KeyManager.h"

namespace jiangweigithub {

  KeyTop::KeyTop(KeyManager* km)
  {
    keyManager = km;
  }

  KeyTop::~KeyTop()
  {

  }

  void KeyTop::pressTop(cocos2d::Sprite* sprite, float& x, float& y)
  {
    if(KeyboardState::obstacle->getTopState() == true)
    {
      keyManager->setState(keyManager->getStateStop());
      keyManager->pressTop(sprite, x, y);

      return;
    }

    // if(KeyboardState::obstacle->getBottomState() == true || KeyboardState::obstacle->getLeftState() == true || KeyboardState::obstacle->getRightState() == true)
    // {
    //   y += 1;
    //   sprite->setPosition(cocos2d::Vec2(x, y));

    //   return;
    // }

    y += 1;
    sprite->setPosition(cocos2d::Vec2(x, y));

    return;
  }

  void KeyTop::pressBottom(cocos2d::Sprite* sprite, float& x, float& y)
  {
    if(KeyboardState::obstacle->getBottomState() == true)
    {
      keyManager->setState(keyManager->getStateStop());

      keyManager->pressBottom(sprite, x, y);

      return;
    }

    // if(KeyboardState::obstacle->getTopState() == true || KeyboardState::obstacle->getLeftState() == true || KeyboardState::obstacle->getRightState() == true)
    // {
    //   // y -= 1;
    //   // sprite->setPosition(cocos2d::Vec2(x, y));

    //   keyManager->setState(keyManager->getStateBottom());
    //   keyManager->pressBottom(sprite, x, y);

    //   return;
    // }

    // // y -= 1;
    // // sprite->setPosition(cocos2d::Vec2(x, y));

    keyManager->setState(keyManager->getStateBottom());
    keyManager->pressBottom(sprite, x, y);

    return;
  }

  void KeyTop::pressLeft(cocos2d::Sprite* sprite, float& x, float& y)
  {
    if(KeyboardState::obstacle->getLeftState() == true)
    {
      keyManager->setState(keyManager->getStateStop());

      keyManager->pressLeft(sprite, x, y);

      return;
    }

    // if(KeyboardState::obstacle->getTopState() == true || KeyboardState::obstacle->getBottomState() == true || KeyboardState::obstacle->getRightState() == true)
    // {
    //   // x -= 1;
    //   // sprite->setPosition(cocos2d::Vec2(x, y));

    //   keyManager->setState(keyManager->getStateLeft());
    //   keyManager->pressLeft(sprite, x, y);

    //   return;
    // }

    // // x -= 1;
    // // sprite->setPosition(cocos2d::Vec2(x, y));

    keyManager->setState(keyManager->getStateLeft());
    keyManager->pressLeft(sprite, x, y);

    return;
  }

  void KeyTop::pressRight(cocos2d::Sprite* sprite, float& x, float& y)
  {
    if(KeyboardState::obstacle->getRightState() == true)
    {
      keyManager->setState(keyManager->getStateStop());

      keyManager->pressRight(sprite, x, y);

      return;
    }

    // if(KeyboardState::obstacle->getTopState() == true || KeyboardState::obstacle->getBottomState() == true || KeyboardState::obstacle->getLeftState() == true)
    // {
    //   // x += 1;
    //   // sprite->setPosition(cocos2d::Vec2(x, y));

    //   keyManager->setState(keyManager->getStateRight());
    //   keyManager->pressRight(sprite, x, y);

    //   return;
    // }

    // // x += 1;
    // // sprite->setPosition(cocos2d::Vec2(x, y));
    
    keyManager->setState(keyManager->getStateRight());
    keyManager->pressRight(sprite, x, y);

    return;
  }

}