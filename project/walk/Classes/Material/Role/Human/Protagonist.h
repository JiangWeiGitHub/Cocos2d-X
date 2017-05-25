#ifndef __PROTAGONIST_H__
#define __PROTAGONIST_H__

#include "../../../Global/Global.h"

namespace jiangweigithub {

  class Protagonist: public Human
  {
  public:
    bool setHeaddress(HEADDRESS stuff);
    HEADDRESS getHeaddress();

    bool setUpperBody(UPPER_BODY stuff);
    UPPER_BODY getUpperBody();

    bool setLowerBody(LOWER_BODY stuff);
    LOWER_BODY getLowerBody();

    bool setAccessory(ACCESSORY stuff);
    ACCESSORY getAccessory();

    bool setAvatar(std::string filePath);
    cocos2d::Sprite* getAvatar();

  private:
    HEADDRESS _headdress;
    UPPER_BODY _upperBody;
    LOWER_BODY _lowerBody;
    ACCESSORY _accessory;

    cocos2d::Sprite* _avatar;
  };
  
}

#endif // __PROTAGONIST_H__