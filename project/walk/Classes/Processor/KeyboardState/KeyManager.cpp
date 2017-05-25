#include "./KeyManager.h"

namespace jiangweigithub {

  KeyManager::KeyManager(std::string name)
  {
    _stateTop = new KeyTop(this);
    _stateBottom = new KeyBottom(this);
    _stateLeft = new KeyLeft(this);
    _stateRight = new KeyRight(this);
    _stateStop = new KeyStop(this);

    if(name == "STOP")
    {
      _state = _stateStop;
    }
    else if(name == "TOP")
    {
      _state = _stateTop;
    }
    else if(name == "BOTTOM")
    {
      _state = _stateBottom;
    }
    else if(name == "LEFT")
    {
      _state = _stateLeft;
    }
    else if(name == "RIGHT")
    {
      _state = _stateRight;
    }
    else
    {
      _state = NULL;
    }
  }

  KeyManager::~KeyManager()
  {
    delete  _stateTop;
    delete  _stateBottom;
    delete  _stateLeft;
    delete  _stateRight;
    delete  _stateStop;

    delete _state;
  }

  void KeyManager::setState(KeyboardState* state)
  {
    _state = state;
  }

  KeyboardState* KeyManager::getStateTop()
  {
    return this->_stateTop;
  }

  KeyboardState* KeyManager::getStateBottom()
  {
    return _stateBottom;
  }

  KeyboardState* KeyManager::getStateLeft()
  {
    return _stateLeft;
  }

  KeyboardState* KeyManager::getStateRight()
  {
    return _stateRight;
  }

  KeyboardState* KeyManager::getStateStop()
  {
    return _stateStop;
  }

  void KeyManager::pressTop(cocos2d::Sprite* sprite, float& x, float& y)
  {
    _state->pressTop(sprite, x, y);
  }

  void KeyManager::pressBottom(cocos2d::Sprite* sprite, float& x, float& y)
  {
    _state->pressBottom(sprite, x, y);
  }

  void KeyManager::pressLeft(cocos2d::Sprite* sprite, float& x, float& y)
  {
    _state->pressLeft(sprite, x, y);
  }

  void KeyManager::pressRight(cocos2d::Sprite* sprite, float& x, float& y)
  {
    _state->pressRight(sprite, x, y);
  }

}
