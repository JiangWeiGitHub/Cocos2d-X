#ifndef __TALKFRAME_H__
#define __TALKFRAME_H__

#include "iostream"
#include "cocos2d.h"

#include "../../Global/Global.h"
#include "../../Material/Login.h"
#include "../../Processor/JsonCpp/json/json.h"
#include "../../Scene/City/Home.h"

namespace jiangweigithub {

  class TalkFrame : public cocos2d::Layer
  {
  public:
    static cocos2d::Layer* getTalkFrame();
    virtual bool init();

    CREATE_FUNC(TalkFrame);

  private:
    void _nextPageCallback(cocos2d::Ref* pSender);
    void _readTalkContents(int id);
    void _dealTalkContents(int id);
    std::string _talkContents;
    unsigned int _lineCounter;
    std::string _avatar;
    std::string _firstLine;
    std::string _secondLine;
    std::string _thirdLine;
    std::string _peopleName;

    unsigned int _position = 0;
    int _counter = 0;

    std::vector<std::string> _line; 
  };
  
}

#endif // __TALKFRAME_H__