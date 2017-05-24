#include "./TalkFrame.h"

namespace jiangweigithub {

  cocos2d::Layer* TalkFrame::getTalkFrame()
  {
    auto tmp = TalkFrame::create();

    return tmp;
  }

  bool TalkFrame::init()
  {
    if(!Layer::create())
    {
      return false;
    }

    _talkContents = "";
    _lineCounter = 0;
    _avatar = "avatar.png";
    _firstLine = "";
    _secondLine = "";
    _thirdLine = "";
    _peopleName = "- 快夸宝宝 -";

    auto drawFrame = MainSprite::getDrawFrame();
    auto leftFlower = MainSprite::getFrameLeftFlowers();
    auto rightFlower = MainSprite::getFrameRightFlowers();

    _readTalkContents(1);
    _dealTalkContents(1);

    auto avatar = MainSprite::getAvatar(_avatar);
    auto firstLine = MainSprite::getFirstLine(_firstLine);
    auto secondeLine = MainSprite::getSecondLine(_secondLine);
    auto thirdLine = MainSprite::getThirdLine(_thirdLine);
    auto peopleName = MainSprite::getPeopleName(_peopleName);

    auto nextPageItem = MainSprite::getNextPageItem();
    nextPageItem->setCallback(CC_CALLBACK_1(TalkFrame::_nextPageCallback, this));

    auto nextPage = MainSprite::getNextPage();

    MainSprite::setFirstLine(_line[_counter++]);
    MainSprite::setSecondLine(_line[_counter++]);
    MainSprite::setThirdLine(_line[_counter++]);

    this->addChild(drawFrame, 0);
    this->addChild(leftFlower, 2);
    this->addChild(rightFlower, 2);
    this->addChild(avatar, 1);
    this->addChild(firstLine, 1);
    this->addChild(secondeLine, 1);
    this->addChild(thirdLine, 1);
    this->addChild(peopleName, 1);
    this->addChild(nextPage, 1);

    return true;
  }

  void TalkFrame::_nextPageCallback(cocos2d::Ref* pSender)
  {
    // _dealTalkContents(1);

    MainSprite::setFirstLine(_line[_counter++]);
    MainSprite::setSecondLine(_line[_counter++]);
    MainSprite::setThirdLine(_line[_counter++]);
  }

  void TalkFrame::_readTalkContents(int id)
  {
    _talkContents = cocos2d::FileUtils::getInstance()->getStringFromFile("scripts/home/001.script");
    // std::cout<<_talkContents<<std::endl;
  }

  void TalkFrame::_dealTalkContents(int id)
  {
    Json::Reader reader;
    Json::Value json_object;
    int tmp = 0;
    if (!(tmp = reader.parse(_talkContents, json_object)))
    {
      std::cout <<tmp<< std::endl;
    }

    unsigned int i = 0;
    for(i = 0; i < json_object["script"]["contents"].size(); i++)
    {
      unsigned int _tmpPosition = 0;
      while(_tmpPosition <= json_object["script"]["contents"][i].asString().size())
      {
        // std::cout<<"_tmpPosition: "<<_tmpPosition<<std::endl;
        // std::cout<<"son: "<<json_object["script"]["contents"][i].asString().substr(_tmpPosition, TALKLINEWIDTH)<<std::endl;
        _line.push_back(json_object["script"]["contents"][i].asString().substr(_tmpPosition, TALKLINEWIDTH));
        _tmpPosition += TALKLINEWIDTH;
      }
    }
  }

}