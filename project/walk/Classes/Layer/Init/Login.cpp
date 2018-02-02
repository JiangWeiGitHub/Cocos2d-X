#include "./Login.h"

namespace jiangweigithub {

  cocos2d::Layer* LoginLayer::getLoginLayer()
  {
    auto tmp = LoginLayer::create();

    return tmp;
  }

  bool LoginLayer::init()
  {
    if(!Layer::create())
    {
      return false;
    }

    this->_background = LoginMaterial::getBackgroundSprite();
    this->_newGame = LoginMaterial::getNewGame();
    this->_loadGame = LoginMaterial::getLoadGame();
    this->_configGame = LoginMaterial::getConfigGame();

    this->_newGame->setCallback(CC_CALLBACK_1(LoginLayer::onNewGame, this));
    this->_loadGame->setCallback(CC_CALLBACK_1(LoginLayer::onLoadGame, this));
    this->_configGame->setCallback(CC_CALLBACK_1(LoginLayer::onConfigGame, this));

    this->_newGame->unselected();
    this->_loadGame->unselected();
    this->_configGame->unselected();

    auto tmp = cocos2d::Menu::create(this->_newGame, this->_loadGame, this->_configGame, NULL);
    tmp->alignItemsVerticallyWithPadding(10);

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();

    this->_background->setPosition(cocos2d::Vec2(visibleSize.width / 2, visibleSize.height / 2));
    tmp->setPosition(cocos2d::Vec2(visibleSize.width / 2, 100));

    // this->addChild(this->_background, -1);
    this->addChild(tmp, 0);

    auto listener = cocos2d::EventListenerKeyboard::create();
    listener->onKeyPressed = CC_CALLBACK_2(LoginLayer::onKeyPressed, this);
    _eventDispatcher->addEventListenerWithSceneGraphPriority(listener, this);

    return true;
  }

  void LoginLayer::onConfigGame(cocos2d::Ref* callback)
  {
    this->gotoHomeScene();
  }

  void LoginLayer::onNewGame(cocos2d::Ref* callback)
  {
    this->gotoHomeScene();
  }

  void LoginLayer::onLoadGame(cocos2d::Ref* callback)
  {
    this->gotoHomeScene();
  }

  void LoginLayer::gotoHomeScene()
  {
    // auto homeScene = jiangweigithub::Home::getHomeScene();
    auto homeScene = jiangweigithub::PrefaceScene::getPrefaceScene();

    cocos2d::Director::getInstance()->replaceScene(homeScene);
  }

  void LoginLayer::onKeyPressed(cocos2d::EventKeyboard::KeyCode keyCode, cocos2d::Event* event)
  {
    switch((int)keyCode)
    {
      case 28:
        // top
        if(this->_newGame->isSelected())
        {
          this->_newGame->unselected();
          this->_loadGame->unselected();
          this->_configGame->selected();
        }
        else if(this->_loadGame->isSelected())
        {
          this->_newGame->selected();
          this->_loadGame->unselected();
          this->_configGame->unselected();
        }
        else if(this->_configGame->isSelected())
        {
          this->_newGame->unselected();
          this->_loadGame->selected();
          this->_configGame->unselected();
        }
        else
        {
          this->_newGame->unselected();
          this->_loadGame->unselected();
          this->_configGame->selected();
        }

        break;
        
      case 29:
        // bottom
        if(this->_newGame->isSelected())
        {
          this->_newGame->unselected();
          this->_loadGame->selected();
          this->_configGame->unselected();
        }
        else if(this->_loadGame->isSelected())
        {
          this->_newGame->unselected();
          this->_loadGame->unselected();
          this->_configGame->selected();
        }
        else if(this->_configGame->isSelected())
        {
          this->_newGame->selected();
          this->_loadGame->unselected();
          this->_configGame->unselected();
        }
        else
        {
          this->_newGame->selected();
          this->_loadGame->unselected();
          this->_configGame->unselected();
        }

        break;

      case 164:
        // enter
        if(this->_newGame->isSelected())
        {
          this->gotoHomeScene();
        }
        else if(this->_loadGame->isSelected())
        {
          this->gotoHomeScene();
        }
        else if(this->_configGame->isSelected())
        {
          this->gotoHomeScene();
        }        

      default:
        break;
    }
  }

}