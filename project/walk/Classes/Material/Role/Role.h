#ifndef __ROLE_H__
#define __ROLE_H__

#pragma once

#include "../../Global/Global.h"

namespace jiangweigithub {

  class Role
  {
  public:
    bool setName(std::string name);
    std::string getName();

    bool setPP(unsigned int pp);
    unsigned int getPP();

    bool setMP(unsigned int mp);
    unsigned int getMP();

    bool setPAP(unsigned int pap);
    unsigned int getPDP();

    bool setPDP(unsigned int pdp);
    unsigned int getName();

    bool setMAP(unsigned int map);
    unsigned int getMAP();

    bool setMDP(unsigned int mdp);
    unsigned int getMDP();

    bool setSP(unsigned int sp);
    unsigned int getSP();

    bool setHP(unsigned int hp);
    unsigned int getHP();

    bool setEP(unsigned int ep);
    unsigned int getEP();

    bool setLP(unsigned int lp);
    unsigned int getLP();

    bool setTextureFile(std::string path);
    std::string getTextureFile();

    cocos2d::Animation* getAnimationTop(std::vector<cocos2d::Rect>& vec);
    cocos2d::Animation* getAnimationBottom(std::vector<cocos2d::Rect>& vec);
    cocos2d::Animation* getAnimationLeft(std::vector<cocos2d::Rect>& vec);
    cocos2d::Animation* getAnimationRight(std::vector<cocos2d::Rect>& vec);

  private:
    std::string _name;
    unsigned int _physicalPoint;
    unsigned int _mentalPoint;
    unsigned int _physicalAttackPoint;
    unsigned int _physicalDefencePoint;
    unsigned int _mentalAttackPoint;
    unsigned int _mentalDefencePoint;
    unsigned int _speedPoint;
    unsigned int _hitPoint;
    unsigned int _evasionPoint;
    unsigned int _luckPoint;

    std::string _textureFilePath;

    cocos2d::Vector<cocos2d::SpriteFrame*> _topFrameVector;
    cocos2d::Vector<cocos2d::SpriteFrame*> _bottomFrameVector;
    cocos2d::Vector<cocos2d::SpriteFrame*> _leftFrameVector;
    cocos2d::Vector<cocos2d::SpriteFrame*> _rightFrameVector;

    cocos2d::Animation* _animationTop;
    cocos2d::Animation* _animationBottom;
    cocos2d::Animation* _animationLeft;
    cocos2d::Animation* _animationRight;
  };
  
}

#endif // __ROLE_H__