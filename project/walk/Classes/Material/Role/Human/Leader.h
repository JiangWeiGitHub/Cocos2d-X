#ifndef __LEADER_H__
#define __LEADER_H__

#include "../../../Global/Global.h"

namespace jiangweigithub {

  class Leader: public Human
  {
  public:
    // Leader();
    // ~Leader();

    static bool setHP(unsigned int number);
    static unsigned int getHP();

    static bool setName(std::string name);
    static std::string getName();

    static cocos2d::Animation* getAnimationTop();
    static cocos2d::Animation* getAnimationBottom();
    static cocos2d::Animation* getAnimationLeft();
    static cocos2d::Animation* getAnimationRight();

  private:
    // static bool createAnimation(std::string fileName);

    static unsigned int HP;
    static std::string heroName;
    static std::string fileName;

    static cocos2d::Vector<cocos2d::SpriteFrame*> top;
    static cocos2d::Vector<cocos2d::SpriteFrame*> bottom;
    static cocos2d::Vector<cocos2d::SpriteFrame*> left;
    static cocos2d::Vector<cocos2d::SpriteFrame*> right;

    static cocos2d::Animation* animationTop;
    static cocos2d::Animation* animationBottom;
    static cocos2d::Animation* animationLeft;
    static cocos2d::Animation* animationRight;
  };
  
}

#endif // __LEADER_H__