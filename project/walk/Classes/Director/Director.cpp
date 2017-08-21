#include "./Director.h"

namespace jiangweigithub {

  cocos2d::Director* Director::director = cocos2d::Director::getInstance();
  enum CHAPTER _chapter = CHAPTER::HOME;

  void Director::initDirector()
  {
    director = cocos2d::Director::getInstance();
    auto glview = director->getOpenGLView();
    if(!glview)
    {
    #if (CC_TARGET_PLATFORM == CC_PLATFORM_WIN32) || (CC_TARGET_PLATFORM == CC_PLATFORM_MAC) || (CC_TARGET_PLATFORM == CC_PLATFORM_LINUX)
      glview = cocos2d::GLViewImpl::createWithRect("walk", cocos2d::Rect(0, 0, designResolutionSize.width, designResolutionSize.height));
    #else
      glview = cocos2d::GLViewImpl::create("walk");
    #endif
    
      director->setOpenGLView(glview);
    }

    director->setDisplayStats(true);

    director->setAnimationInterval(1.0f / 60);

    glview->setDesignResolutionSize(designResolutionSize.width, designResolutionSize.height, ResolutionPolicy::NO_BORDER);
    auto frameSize = glview->getFrameSize();
    if (frameSize.height > mediumResolutionSize.height)
    {        
      director->setContentScaleFactor(MIN(largeResolutionSize.height/designResolutionSize.height, largeResolutionSize.width/designResolutionSize.width));
    }
    else if (frameSize.height > smallResolutionSize.height)
    {        
      director->setContentScaleFactor(MIN(mediumResolutionSize.height/designResolutionSize.height, mediumResolutionSize.width/designResolutionSize.width));
    }
    else
    {        
      director->setContentScaleFactor(MIN(smallResolutionSize.height/designResolutionSize.height, smallResolutionSize.width/designResolutionSize.width));
    }
  }

  void Director::switchLoginScene()
  {
    auto scene = jiangweigithub::Login::getLoginScene();
    director->runWithScene(scene);
  }

  void Director::openLoadingScene()
  {
    auto scene = LoadingScene::getLoadingScene();
    director->runWithScene(scene);
  }

  void Director::loadingSceneCallback()
  {
    auto loginScene = jiangweigithub::Login::getLoginScene();
    director->replaceScene(loginScene);
  }

  void Director::loginSceneCallback()
  {
    auto homeScene = jiangweigithub::Home::getHomeScene();
    director->replaceScene(homeScene);
  }

  void Director::setChapter(enum CHAPTER chapter)
  {
    _chapter = chapter;
  }

  enum CHAPTER Director::getChapter()
  {
    return _chapter;
  }

}