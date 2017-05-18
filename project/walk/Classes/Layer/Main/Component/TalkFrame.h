#ifndef __TALKFRAME_H__
#define __TALKFRAME_H__

#include "iostream"
#include "cocos2d.h"

#include "../../../Sprite/Main/MainSprite.h"

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

    int _position = 0;
  };
  
}

#endif // __TALKFRAME_H__