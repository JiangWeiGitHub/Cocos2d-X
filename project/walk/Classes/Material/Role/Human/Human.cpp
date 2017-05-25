#include "./Human.h"

namespace jiangweigithub {

  bool Human::setTalkContents(std::string contents)
  {
    this->_talkContents = contents;

    return true;
  }

  std::string Human::getTalkContents()
  {
    return this->_talkContents;
  }

  bool Human::setSex(SEX sex)
  {
    this->_sex = sex;

    return true;
  }

  SEX Human::getSex()
  {
    return this->_sex;
  }

  bool Human::setMood(MOOD mood)
  {
    this->_mood = mood;

    return true;
  }

  MOOD Human::getMood()
  {
    return this->_mood;
  }

  bool Human::setMovePosition(cocos2d::Point position)
  {
    (this->_position).x = position.x;
    (this->_position).y = position.y;

    return true;
  }

  cocos2d::Point Human::getMovePosition()
  {
    return this->_position;
  }

}