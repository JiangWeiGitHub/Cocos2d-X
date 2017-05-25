#ifndef __PREFACELAYER_H__
#define __PREFACELAYER_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../../Global/Global.h"
#include "../../../Producer/JsonCpp/json/json.h"
#include "../../../Scene/Main/Home/Home.h"

namespace jiangweigithub {
  
  class PrefaceLayer : public cocos2d::Layer
  {
  public:
    static cocos2d::Layer* getPrefaceLayer();
    virtual bool init();

    CREATE_FUNC(PrefaceLayer);

  private:
    void update(float delta) override;
    void _gotoHomeScene();
    void _nextPageCallback(cocos2d::Ref* pSender);

    cocos2d::Label* _text = NULL;
    cocos2d::Size _textSize;
    int counter = 0;
  };

}

#endif // __PREFACELAYER_H__