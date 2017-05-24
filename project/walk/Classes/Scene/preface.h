#ifndef __PREFACESCENE_H__
#define __PREFACESCENE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../../Layer/Main/Preface/Preface.h"

namespace jiangweigithub {

  class PrefaceScene : public cocos2d::Scene
  {
  public:
    static cocos2d::Scene* getPrefaceScene();
    virtual bool init();

    CREATE_FUNC(PrefaceScene);

  };

}

#endif // __PREFACESCENE_H__