#include "./Preface.h"

namespace jiangweigithub {

  cocos2d::Layer* PrefaceLayer::getPrefaceLayer()
  {
    auto tmp = PrefaceLayer::create();

    return tmp;
  }

  bool PrefaceLayer::init()
  {
    if(!Layer::create())
    {
      return false;
    }

    auto visibleSize = cocos2d::Director::getInstance()->getVisibleSize();
    cocos2d::Vec2 origin = cocos2d::Director::getInstance()->getVisibleOrigin();

    auto _prefaceContents = cocos2d::FileUtils::getInstance()->getStringFromFile("scripts/preface/001.script");
    Json::Reader reader;
    Json::Value json_object;
    int tmp = 0;
    if (!(tmp = reader.parse(_prefaceContents, json_object)))
    {
      std::cout <<tmp<< std::endl;
    }

    unsigned int i = 0;
    std::vector<std::string> _line;
    for(i = 0; i < json_object["script"]["contents"].size(); i++)
    {
      unsigned int _tmpPosition = 0;
      while(_tmpPosition <= json_object["script"]["contents"][i].asString().size())
      {
        _line.push_back(json_object["script"]["contents"][i].asString().substr(_tmpPosition, PREFACEWIDTH));
        _tmpPosition += PREFACEWIDTH;
      }
    }

    std::string _prefaceLine = "";
    unsigned int aaa = 0;
    while(aaa <= _line.size() - 5)
    {
      _prefaceLine += *(_line.begin() + aaa);
      _prefaceLine += "\n";
      aaa++;
    }

    this->_text = cocos2d::Label::createWithTTF(_prefaceLine, "fonts/MSYHBD.TTF", 22);

    this->_textSize = _text->getContentSize();
    this->_text->setAnchorPoint(cocos2d::Vec2(0, 0));
    this->_text->enableOutline(cocos2d::Color4B(0, 0, 0, 200), 2);

    (this->_text)->setPosition(cocos2d::Vec2((visibleSize.width - _textSize.width) / 2, -(this->_textSize).height - 100));
    
    cocos2d::DrawNode* shape = cocos2d::DrawNode::create();

    cocos2d::Vec2 point[4];
    point[0] = cocos2d::Vec2(visibleSize.width / 2 - 600, visibleSize.height / 2 - 200);
    point[1] = cocos2d::Vec2(visibleSize.width / 2 + 600, visibleSize.height / 2 - 200);
    point[2] = cocos2d::Vec2(visibleSize.width / 2 + 600, visibleSize.height / 2 + 200);
    point[3] = cocos2d::Vec2(visibleSize.width / 2 - 600, visibleSize.height / 2 + 200);
    shape->drawPolygon(point, 4, cocos2d::Color4F(66/255.0f, 66/255.0f, 66/255.0f, 0.5f), 1, cocos2d::Color4F(243/255.0f, 198/255.0f, 108/255.0f, 0.7f));    

    cocos2d::ClippingNode* cliper = cocos2d::ClippingNode::create();
    cliper->setStencil(shape);  
    cliper->setAnchorPoint(cocos2d::Vec2(0, 0));
    cliper->addChild(this->_text);

    this->addChild(cliper, 0);

    auto nextPageItem = MainSprite::getNextPageItem();
    nextPageItem->setCallback(CC_CALLBACK_1(PrefaceLayer::_nextPageCallback, this));
    auto nextPage = MainSprite::getNextPage();

    this->addChild(nextPage, 1);

    this->scheduleUpdate();

    return true;  
  }

  void PrefaceLayer::_nextPageCallback(cocos2d::Ref* pSender)
  {
    this->_gotoHomeScene();
  }

  void PrefaceLayer::update(float delta)
  {
    if(this->counter > PREFACESPEED)
    {
      this->_text->getPositionY() > 500 ? this->_gotoHomeScene() : this->_text->setPositionY(this->_text->getPositionY() + 1);
      this->counter = 0;
    }
    else
    {
      this->counter++;
    }
  }

  void PrefaceLayer::_gotoHomeScene()
  {
    auto homeScene = jiangweigithub::Home::getHomeScene();
    cocos2d::Director::getInstance()->replaceScene(homeScene);
  }

}