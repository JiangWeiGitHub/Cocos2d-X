#ifndef __GLOBAL_H__
#define __GLOBAL_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

namespace jiangweigithub {

  #define TALKLINE_WIDTH 111
  #define PREFACE_WIDTH 99
  #define PREFACE_SPEED 2
  #define TALK_FRAME_EDGE 2
  #define TALK_FRAME_ARROW_WIDTH 10
  #define TALK_FRAME_ARROW_HEIGHT 10

  #define ROLE_SIZE_WIDTH 30
  #define ROLE_SIZE_HEIGHT 50

  #define FRAMES_DELAY 0.2f

  enum SEX
  {
    MAN = 1,
    WOMAN = 2,
  };

  enum MOOD
  {
    GOOD = 1,
    NORMAL = 2,
    BAD = 3,
  };

  enum TALK_FRAME_ARROW_DIRECTION
  {
    LEFT = 1,
    RIGHT = 2,
  };

  enum CHAPTER
  {
    // >>>>>>>>>>>>>>>>>
    HOME =    10000,
    MYROOM =  10100,

    // >>>>>>>>>>>>>>>>>
    TOWN = 20000,

    // >>>>>>>>>>>>>>>>>
    FIELD = 30000,

    // >>>>>>>>>>>>>>>>>
    FOREST = 40000,

    // >>>>>>>>>>>>>>>>>
    CASTLE = 50000,
  };

  enum HEADDRESS
  {
    HAT = 1,
    TIARA = 2,

    HEADDRESS_EMPTY = 999,
  };

  enum UPPER_BODY
  {
    GLOVES = 1,

    UPPER_BODY_EMPTY = 999,
  };

  enum LOWER_BODY
  {
    BOOTS = 1,

    LOWER_BODY_EMPTY = 999,
  };

  enum ACCESSORY
  {
    RING = 1,

    ACCESSORY_EMPTY = 999,
  };
}

#endif // __GLOBAL_H__