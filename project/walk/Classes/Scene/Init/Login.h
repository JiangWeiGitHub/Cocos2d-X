#ifndef __LOGIN_H__
#define __LOGIN_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

#include "../../Layer/Init/Login.h"

namespace jiangweigithub {

  class Login : public cocos2d::Scene
  {
  public:
    static cocos2d::Scene* getLoginScene();
    virtual bool init();

    CREATE_FUNC(Login);
  };

}

#endif // __LOGIN_H__