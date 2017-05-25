#include "./KeyLeft.h"
#include "./KeyManager.h"

namespace jiangweigithub {

  KeyLeft::KeyLeft(KeyManager* km)
  {
    keyManager = km;
  }

  KeyLeft::~KeyLeft()
  {

  }

  void KeyLeft::pressTop(cocos2d::Sprite* sprite, float& x, float& y)
  {
    // if(KeyboardState::obstacle->getTopState() == true)
    // {
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

  void KeyLeft::pressBottom(cocos2d::Sprite* sprite, float& x, float& y)
  {
    // if(KeyboardState::obstacle->getBottomState() == true)
    // {
    //   if(obstacle->getException() == Obstacle::BOTTOM)
    //   {
    //     keyManager->setState(keyManager->getStateBottom());
    //   }
    //   else
    //   {
    //     keyManager->setState(keyManager->getStateStop());
    //   }

    //   keyManager->pressBottom(sprite, x, y);

    //   return;
    // }

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

  void KeyLeft::pressLeft(cocos2d::Sprite* sprite, float& x, float& y)
  {
    if(KeyboardState::obstacle->getLeftState() == true)
    {
      keyManager->setState(keyManager->getStateStop());
      keyManager->pressLeft(sprite, x, y);

      return;
    }

    // if(KeyboardState::obstacle->getTopState() == true || KeyboardState::obstacle->getBottomState() == true || KeyboardState::obstacle->getRightState() == true)
    // {
    //   x -= 1;
    //   sprite->setPosition(cocos2d::Vec2(x, y));

    //   return;
    // }

    x -= 1;
    sprite->setPosition(cocos2d::Vec2(x, y));
    
    return;
  }

  void KeyLeft::pressRight(cocos2d::Sprite* sprite, float& x, float& y)
  {
    // if(KeyboardState::obstacle->getRightState() == true)
    // {
    //   if(obstacle->getException() == Obstacle::RIGHT)
    //   {
    //     keyManager->setState(keyManager->getStateRight());
    //   }
    //   else
    //   {
    //     keyManager->setState(keyManager->getStateStop());
    //   }

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