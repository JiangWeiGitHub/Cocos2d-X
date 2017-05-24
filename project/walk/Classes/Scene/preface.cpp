#include "./Preface.h"

namespace jiangweigithub {

  cocos2d::Scene* PrefaceScene::getPrefaceScene()
  {
    auto tmp = PrefaceScene::create();

    return tmp;
  }

  bool PrefaceScene::init()
  {
    if(!cocos2d::Scene::init()) 
    {
      return false;
    }

    auto lineFrame  = MainSprite::getLittleTalkFrame(30, 30, littleTalkFrameArrowDirection::RIGHT,
                        1, cocos2d::Color4F(200/255.0f, 200/255.0f, 200/255.0f, 0.7f),
                        cocos2d::Color4F(50/255.0f, 50/255.0f, 50/255.0f, 0.5f)
                      );

    auto lineSize = lineFrame->getContentSize();
    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    lineFrame->setAnchorPoint(cocos2d::Vec2(0, 0));
    lineFrame->setPosition(cocos2d::Vec2((visibleSize.width - lineSize.width) / 2, (visibleSize.height - lineSize.height) / 2));

    this->addChild(lineFrame, 1);

    return true;
  }

}