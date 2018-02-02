#ifndef __MAINSPRITE_H__
#define __MAINSPRITE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../Global/Global.h"
#include "../Scene/City/Home.h"

namespace jiangweigithub {

  class HomeMaterial
  {
  public:
    // Home
    static cocos2d::Sprite* getLeaderSprite();
    static cocos2d::Label* getHomeTitle();
    static cocos2d::TMXTiledMap* getTileMapSprite();

    // Login
    static cocos2d::Sprite* getBackgroundSprite();
    static cocos2d::MenuItemLabel* getNewGame();
    static cocos2d::MenuItemLabel* getLoadGame();
    static cocos2d::MenuItemLabel* getConfigGame();

    // Dialog box
    static cocos2d::DrawNode* getDrawFrame();
    static cocos2d::Sprite* getFrameLeftFlowers();
    static cocos2d::Sprite* getFrameRightFlowers();

    static cocos2d::Sprite* getAvatar(std::string contents);
    static void setAvatar(std::string contents);
    static cocos2d::Label* getFirstLine(std::string contents);
    static void setFirstLine(std::string contents);
    static cocos2d::Label* getSecondLine(std::string contents);
    static void setSecondLine(std::string contents);
    static cocos2d::Label* getThirdLine(std::string contents);
    static void setThirdLine(std::string contents);
    static cocos2d::Label* getPeopleName(std::string contents);
    static void setPeopleName(std::string contents);

    static cocos2d::MenuItemImage* getNextPageItem();
    static cocos2d::Menu* getNextPage();

    static cocos2d::DrawNode* getLittleTalkFrame(int width, int height,
                                TALK_FRAME_ARROW_DIRECTION direction,
                                float lineWidth, cocos2d::Color4F lineColor,
                                cocos2d::Color4F fillColor
                              );

  private:
    static cocos2d::Sprite* _avatar;
    static cocos2d::Label* _firstLine;
    static cocos2d::Label* _secondLine;
    static cocos2d::Label* _thirdLine;
    static cocos2d::Label* _peopleName;

    static cocos2d::MenuItemImage* _nextPageItem;
  };
  
}

#endif // __HOMEMATERIAL_H__