#include "./Login.h"

namespace jiangweigithub {

  cocos2d::Scene* Login::getLoginScene()
  {
    auto tmp = Login::create();

    return tmp;
  }

  bool Login::init()
  {
    if(!Scene::create())
    {
      return false;
    }

    auto tmp = LoginLayer::getLoginLayer();
    this->addChild(tmp);

    return true;
  }

}