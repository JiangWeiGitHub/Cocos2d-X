#include "./Protagonist.h"

namespace jiangweigithub {

  bool Protagonist::setHeaddress(HEADDRESS stuff)
  {
    this->_headdress = stuff;

    return true;
  }

  HEADDRESS Protagonist::getHeaddress()
  {
    return this->_headdress;
  }

  bool Protagonist::setUpperBody(UPPER_BODY stuff)
  {
    this->_upperBody = stuff;

    return true;
  }

  UPPER_BODY Protagonist::getUpperBody()
  {
    return this->_upperBody;
  }

  bool Protagonist::setLowerBody(LOWER_BODY stuff)
  {
    this->_lowerBody = stuff;

    return true;
  }

  LOWER_BODY Protagonist::getLowerBody()
  {
    return this->_lowerBody;
  }

  bool Protagonist::setAccessory(ACCESSORY stuff)
  {
    this->_accessory = stuff;

    return true;
  }

  ACCESSORY Protagonist::getAccessory()
  {
    return this->_accessory;
  }

  bool Protagonist::setAvatar(std::string filePath)
  {
    this->_avatar = cocos2d::Sprite::create(filePath);

    return true;
  }

  cocos2d::Sprite* Protagonist::getAvatar()
  {
    return this->_avatar;
  }

}