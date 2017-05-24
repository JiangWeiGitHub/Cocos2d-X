#ifndef __HOME_H__
#define __HOME_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../../Layer/Main/Home/HomeLayer.h"
#include "../../../Layer/Main/Component/TalkFrame.h"

namespace jiangweigithub {

  class Home : public cocos2d::Scene
  {
  public:
    static cocos2d::Scene* getHomeScene();
    virtual bool init();

    CREATE_FUNC(Home);
  };

}

#endif // __HOME_H__