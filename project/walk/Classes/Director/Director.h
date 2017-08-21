#ifndef __DIRECTOR_H__
#define __DIRECTOR_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../Global/Global.h"
#include "../Scene/Init/Loading.h"

static cocos2d::Size designResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size smallResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size mediumResolutionSize = cocos2d::Size(1280, 720);
static cocos2d::Size largeResolutionSize = cocos2d::Size(1280, 720);

namespace jiangweigithub {

  class Director
  {
  public:
    static void initDirector();
    static void switchLoginScene();

    static void openLoadingScene();
    static void loadingSceneCallback();
    static void loginSceneCallback();

    static enum CHAPTER getChapter();
    void setChapter(enum CHAPTER chapter);

    static cocos2d::Director* director;

  private:
    static enum CHAPTER _chapter;
  };

}

#endif // __DIRECTOR_H__