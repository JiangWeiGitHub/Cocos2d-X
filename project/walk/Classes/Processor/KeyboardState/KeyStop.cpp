#include "./KeyStop.h"
#include "./KeyManager.h"

namespace jiangweigithub {

  KeyStop::KeyStop(KeyManager* km)
  {
    keyManager = km;
  }

  KeyStop::~KeyStop()
  {

  }

  void KeyStop::pressTop(cocos2d::Sprite* sprite, float& x, float& y)
  {
    if(KeyboardState::obstacle->getTopState() == true)
    {
      // if(obstacle->getException() == Obstacle::TOP)
      // {
      //   keyManager->setState(keyManager->getStateTop());
      //   keyManager->pressTop(sprite, x, y);
      // }

      return;
    }

    // if(KeyboardState::obstacle->getBottomState() == true || KeyboardState::obstacle->getLeftState() == true || KeyboardState::obstacle->getRightState() == true)
    // {
    //   keyManager->setState(keyManager->getStateTop());
    //   keyManager->pressTop(sprite, x, y);

    //   return;
    // }

    keyManager->setState(keyManager->getStateTop());
    keyManager->pressTop(sprite, x, y);

    return;
  }

  void KeyStop::pressBottom(cocos2d::Sprite* sprite, float& x, float& y)
  {
    if(KeyboardState::obstacle->getBottomState() == true)
    {
      // if(obstacle->getException() == Obstacle::BOTTOM)
      // {
      //   keyManager->setState(keyManager->getStateBottom());
      //   keyManager->pressBottom(sprite, x, y);
      // }

      return;
    }

    // if(KeyboardState::obstacle->getTopState() == true || KeyboardState::obstacle->getLeftState() == true || KeyboardState::obstacle->getRightState() == true)
    // {
    //   keyManager->setState(keyManager->getStateBottom());
    //   keyManager->pressBottom(sprite, x, y);

    //   return;
    // }

    keyManager->setState(keyManager->getStateBottom());
    keyManager->pressBottom(sprite, x, y);

    return;
  }

  void KeyStop::pressLeft(cocos2d::Sprite* sprite, float& x, float& y)
  {
    if(KeyboardState::obstacle->getLeftState() == true)
    {
      // if(obstacle->getException() == Obstacle::LEFT)
      // {
      //   keyManager->setState(keyManager->getStateLeft());
      //   keyManager->pressLeft(sprite, x, y);
      // }

      return;
    }

    // if(KeyboardState::obstacle->getTopState() == true || KeyboardState::obstacle->getBottomState() == true || KeyboardState::obstacle->getRightState() == true)
    // {
    //   keyManager->setState(keyManager->getStateLeft());
    //   keyManager->pressLeft(sprite, x, y);

    //   return;
    // }

    keyManager->setState(keyManager->getStateLeft());
    keyManager->pressLeft(sprite, x, y);
    
    return;
  }

  void KeyStop::pressRight(cocos2d::Sprite* sprite, float& x, float& y)
  {
    if(KeyboardState::obstacle->getRightState() == true)
    {
      // if(obstacle->getException() == Obstacle::RIGHT)
      // {
      //   keyManager->setState(keyManager->getStateRight());
      //   keyManager->pressRight(sprite, x, y);
      // }

      return;
    }

    // if(KeyboardState::obstacle->getTopState() == true || KeyboardState::obstacle->getBottomState() == true || KeyboardState::obstacle->getLeftState() == true)
    // {
    //   keyManager->setState(keyManager->getStateRight());
    //   keyManager->pressRight(sprite, x, y);

    //   return;
    // }

    keyManager->setState(keyManager->getStateRight());
    keyManager->pressRight(sprite, x, y);
    
    return;
  }

}