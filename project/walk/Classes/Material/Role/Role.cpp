#include "Role.h"

namespace jiangweigithub {

  bool Role::init()
  {
    if (!Sprite::init())
    {
      return false;
    }


    return true;
  }

  bool Role::setName(std::string name)
  {
    this->_name = name;

    return true;
  }

  std::string Role::getName()
  {
    return this->_name;
  }

  bool Role::setPP(unsigned int pp)
  {
    this->_physicalPoint = pp;

    return true;
  }

  unsigned int Role::getPP()
  {
    return this->_physicalPoint;
  }

  bool Role::setMP(unsigned int mp)
  {
    this->_mentalPoint = mp;

    return true;
  }

  unsigned int Role::getMP()
  {
    return this->_mentalPoint;
  }

  bool Role::setPAP(unsigned int pap)
  {
    this->_physicalAttackPoint = pap;

    return true;
  }

  unsigned int Role::getPDP()
  {
    return this->_physicalAttackPoint;
  }

  bool Role::setPDP(unsigned int pdp)
  {
    this->_physicalDefencePoint = pdp;

    return true;
  }

  bool Role::setMAP(unsigned int map)
  {
    this->_mentalAttackPoint = map;

    return true;
  }

  unsigned int Role::getMAP()
  {
    return this->_mentalAttackPoint;
  }

  bool Role::setMDP(unsigned int mdp)
  {
    this->_mentalDefencePoint = mdp;

    return true;
  }

  unsigned int Role::getMDP()
  {
    return this->_mentalDefencePoint;
  }

  bool Role::setSP(unsigned int sp)
  {
    this->_speedPoint = sp;

    return true;
  }

  unsigned int Role::getSP()
  {
    return this->_speedPoint;
  }

  bool Role::setHP(unsigned int hp)
  {
    this->_hitPoint = hp;

    return true;
  }

  unsigned int Role::getHP()
  {
    return this->_hitPoint;
  }

  bool Role::setEP(unsigned int ep)
  {
    this->_evasionPoint = ep;

    return true;
  }

  unsigned int Role::getEP()
  {
    return this->_evasionPoint;
  }

  bool Role::setLP(unsigned int lp)
  {
    this->_luckPoint = lp;

    return true;
  }

  unsigned int Role::getLP()
  {
    return this->_luckPoint;
  }

  bool Role::setTextureFile(std::string path)
  {
    this->_textureFilePath = path;

    return true;
  }

  std::string Role::getTextureFile()
  {
    return this->_textureFilePath;
  }

  cocos2d::Animation* Role::getAnimationTop(std::vector<cocos2d::Rect>& vec)
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(this->_textureFilePath);

    for(std::vector<cocos2d::Rect>::const_iterator iter = vec.cbegin(); iter != vec.cend(); iter++)
    {
      cocos2d::SpriteFrame* tmp = cocos2d::SpriteFrame::createWithTexture(textTure, (*iter));
      (this->_topFrameVector).pushBack(tmp);
    }

    this->_animationTop = cocos2d::Animation::createWithSpriteFrames(this->_topFrameVector, FRAMES_DELAY);

    return this->_animationTop;
  }

  cocos2d::Animation* Role::getAnimationBottom(std::vector<cocos2d::Rect>& vec)
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(this->_textureFilePath);

    for(std::vector<cocos2d::Rect>::const_iterator iter = vec.cbegin(); iter != vec.cend(); iter++)
    {
      cocos2d::SpriteFrame* tmp = cocos2d::SpriteFrame::createWithTexture(textTure, (*iter));
      (this->_bottomFrameVector).pushBack(tmp);
    }

    this->_animationBottom = cocos2d::Animation::createWithSpriteFrames(this->_bottomFrameVector, FRAMES_DELAY);

    return this->_animationBottom;
  }

  cocos2d::Animation* Role::getAnimationLeft(std::vector<cocos2d::Rect>& vec)
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(this->_textureFilePath);

    for(std::vector<cocos2d::Rect>::const_iterator iter = vec.cbegin(); iter != vec.cend(); iter++)
    {
      cocos2d::SpriteFrame* tmp = cocos2d::SpriteFrame::createWithTexture(textTure, (*iter));
      (this->_leftFrameVector).pushBack(tmp);
    }

    this->_animationLeft = cocos2d::Animation::createWithSpriteFrames(this->_leftFrameVector, FRAMES_DELAY);

    return this->_animationLeft;
  }

  cocos2d::Animation* Role::getAnimationRight(std::vector<cocos2d::Rect>& vec)
  {
    cocos2d::Texture2D* textTure = cocos2d::Director::getInstance()->getTextureCache()->addImage(this->_textureFilePath);

    for(std::vector<cocos2d::Rect>::const_iterator iter = vec.cbegin(); iter != vec.cend(); iter++)
    {
      cocos2d::SpriteFrame* tmp = cocos2d::SpriteFrame::createWithTexture(textTure, (*iter));
      (this->_rightFrameVector).pushBack(tmp);
    }

    this->_animationRight = cocos2d::Animation::createWithSpriteFrames(this->_rightFrameVector, FRAMES_DELAY);

    return this->_animationRight;
  }

}