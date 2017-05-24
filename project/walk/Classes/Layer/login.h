#ifndef __LOGINLAYER_H__
#define __LOGINLAYER_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../../Sprite/Main/MainSprite.h"
#include "../../../Scene/Main/Preface/Preface.h"

namespace jiangweigithub {
  
  class LoginLayer : public cocos2d::Layer
  {
  public:
    static cocos2d::Layer* getLoginLayer();
    virtual bool init();

    CREATE_FUNC(LoginLayer);

  private:
    // Login callback
    void onConfigGame(cocos2d::Ref* callback);
    void onNewGame(cocos2d::Ref* callback);
    void onLoadGame(cocos2d::Ref* callback);

    void onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event);

    void gotoHomeScene();

    cocos2d::Sprite* _background = NULL;
    cocos2d::MenuItemLabel* _newGame = NULL;
    cocos2d::MenuItemLabel* _loadGame = NULL;
    cocos2d::MenuItemLabel* _configGame = NULL;
  };

}

#endif // __LOGINLAYER_H__