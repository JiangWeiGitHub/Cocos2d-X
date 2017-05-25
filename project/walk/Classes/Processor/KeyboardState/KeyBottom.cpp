#include "./KeyBottom.h"
#include "./KeyManager.h"

namespace jiangweigithub {

  KeyBottom::KeyBottom(KeyManager* km)
  {
    keyManager = km;
  }

  KeyBottom::~KeyBottom()
  {

  }

  void KeyBottom::pressTop(cocos2d::Sprite* sprite, float& x, float& y)
  {
    // if(KeyboardState::obstacle->getTopState() == true)
    // {
    //   // if(obstacle->geBlockDirection() == Obstacle::TOP)
    //   // {
    //   //   keyManager->setState(keyManager->getStateStop());
    //   // }
    //   // else
    //   // {
    //   //   keyManager->setState(keyManager->getStateTop());
    //   // }

    //   keyManager->setState(keyManager->getStateStop());

    //   keyManager->pressTop(sprite, x, y);

    //   return;
    // }

    // if(KeyboardState::obstacle->getBottomState() == true || KeyboardState::obstacle->getLeftState() == true || KeyboardState::obstacle->getRightState() == true)
    // {
    //   // y += 1;
    //   // sprite->setPosition(cocos2d::Vec2(x, y));

    //   keyManager->setState(keyManager->getStateTop());
    //   keyManager->pressTop(sprite, x, y);

    //   return;
    // }

    // // y += 1;
    // // sprite->setPosition(cocos2d::Vec2(x, y));

    keyManager->setState(keyManager->getStateTop());
    keyManager->pressTop(sprite, x, y);

    return;
  }

  void KeyBottom::pressBottom(cocos2d::Sprite* sprite, float& x, float& y)
  {
    if(KeyboardState::obstacle->getBottomState() == true)
    {
      keyManager->setState(keyManager->getStateStop());
      keyManager->pressBottom(sprite, x, y);  

      return;
    }

    // if(KeyboardState::obstacle->getTopState() == true || KeyboardState::obstacle->getLeftState() == true || KeyboardState::obstacle->getRightState() == true)
    // {
    //   y -= 1;
    //   sprite->setPosition(cocos2d::Vec2(x, y));

    //   return;
    // }

    y -= 1;
    sprite->setPosition(cocos2d::Vec2(x, y));

    return;
  }

  void KeyBottom::pressLeft(cocos2d::Sprite* sprite, float& x, float& y)
  {
    // if(KeyboardState::obstacle->getLeftState() == true)
    // {
    //   keyManager->setState(keyManager->getStateStop());

    //   keyManager->pressLeft(sprite, x, y);

    //   return;
    // }

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

  void KeyBottom::pressRight(cocos2d::Sprite* sprite, float& x, float& y)
  {
    // if(KeyboardState::obstacle->getRightState() == true)
    // {
    //   keyManager->setState(keyManager->getStateRight());

    //   keyManager->pressRight(sprite, x, y);

    //   return;
    // }

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