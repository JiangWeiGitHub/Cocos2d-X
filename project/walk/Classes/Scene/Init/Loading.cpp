#include "./LoadingScene.h"

namespace jiangweigithub {

  bool LoadingScene::init()
  {
    if(!Scene::init())
    {
      return false;
    }

    auto tmp = LoadingLayer::getLoadingLayer();
    this->addChild(tmp);

    auto closeItem = cocos2d::MenuItemImage::create(
                                            "CloseNormal.png",
                                            "CloseSelected.png",
                                            CC_CALLBACK_1(LoadingScene::menuCloseCallback, this));
    
    closeItem->setPosition(cocos2d::Vec2(1100 ,100));
    auto menu = cocos2d::Menu::create(closeItem, NULL);
    menu->setPosition(cocos2d::Vec2::ZERO);
    this->addChild(menu, 1);

    cocos2d::Director::getInstance()->getTextureCache()
                                    ->addImageAsync("Sabin.png", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    cocos2d::Director::getInstance()->getTextureCache()
                                    ->addImageAsync("backgroud.png", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    cocos2d::Director::getInstance()->getTextureCache()
                                    ->addImageAsync("Inside_A1.png", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    cocos2d::Director::getInstance()->getTextureCache()
                                    ->addImageAsync("Inside_A2.png", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    cocos2d::Director::getInstance()->getTextureCache()
                                    ->addImageAsync("Inside_A4.png", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    cocos2d::Director::getInstance()->getTextureCache()
                                    ->addImageAsync("Inside_A5.png", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    cocos2d::Director::getInstance()->getTextureCache()
                                    ->addImageAsync("Inside_B.png", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    cocos2d::Director::getInstance()->getTextureCache()
                                    ->addImageAsync("Inside_C.png", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    // cocos2d::Director::getInstance()->getTextureCache()
    //                                 ->addImageAsync("1.jpg", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    // cocos2d::Director::getInstance()->getTextureCache()
    //                                 ->addImageAsync("2.jpg", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    // cocos2d::Director::getInstance()->getTextureCache()
    //                                 ->addImageAsync("3.jpg", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    // cocos2d::Director::getInstance()->getTextureCache()
    //                                 ->addImageAsync("4.jpg", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    // cocos2d::Director::getInstance()->getTextureCache()
    //                                 ->addImageAsync("5.jpg", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    // cocos2d::Director::getInstance()->getTextureCache()
    //                                 ->addImageAsync("6.jpg", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    // cocos2d::Director::getInstance()->getTextureCache()
    //                                 ->addImageAsync("7.jpg", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    // cocos2d::Director::getInstance()->getTextureCache()
    //                                 ->addImageAsync("8.jpg", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    // cocos2d::Director::getInstance()->getTextureCache()
    //                                 ->addImageAsync("9.jpg", CC_CALLBACK_1(LoadingScene::loadingCallback, this));
    // cocos2d::Director::getInstance()->getTextureCache()
    //                                 ->addImageAsync("10.jpg", CC_CALLBACK_1(LoadingScene::loadingCallback, this));

    return true;
  }

  cocos2d::Scene* LoadingScene::getLoadingScene()
  {
    auto tmp = LoadingScene::create();
    return tmp;
  }

  void LoadingScene::menuCloseCallback(cocos2d::Ref* pSender)
  {
    auto homeScene = jiangweigithub::Home::getHomeScene();
    // cocos2d::Director::getInstance()->end();
    cocos2d::Director::getInstance()->replaceScene(homeScene);

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
      exit(0);
    #endif
  }

  void LoadingScene::loadingCallback(cocos2d::Ref* callback)
  {
    if((this->_counter)++ >= 7)
    {
      Director::loadingSceneCallback();
    }
  }

}