#ifndef __LEADER_H__
#define __LEADER_H__

#include "../../../Global/Global.h"
#include "./Human.h"

namespace jiangweigithub {

  class Leader: public Human
  {
  public:
    // Leader();
    // ~Leader();

    bool setHP(unsigned int number);
    unsigned int getHP();

    bool setName(std::string name);
    std::string getName();

    cocos2d::Animation* getAnimationTop();
    cocos2d::Animation* getAnimationBottom();
    cocos2d::Animation* getAnimationLeft();
    cocos2d::Animation* getAnimationRight();

  private:
    // static bool createAnimation(std::string fileName);

    unsigned int HP;
    std::string heroName;
    std::string fileName;

    cocos2d::Vector<cocos2d::SpriteFrame*> top;
    cocos2d::Vector<cocos2d::SpriteFrame*> bottom;
    cocos2d::Vector<cocos2d::SpriteFrame*> left;
    cocos2d::Vector<cocos2d::SpriteFrame*> right;

    cocos2d::Animation* animationTop;
    cocos2d::Animation* animationBottom;
    cocos2d::Animation* animationLeft;
    cocos2d::Animation* animationRight;
  };
  
}

#endif // __LEADER_H__