#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__

#pragma once

#include "iostream"
#include "cocos2d.h"

namespace jiangweigithub {

  class Obstacle
  {
  public:
    static Obstacle* getInstance();
    ~Obstacle();

    enum BLOCKDIRECTION
    {
      TOP = 1,
      BOTTOM = 2,
      LEFT = 3,
      RIGHT = 4,
      NONE = 5
    };

    void obstacleTop() { _obstacleTop = true; };
    void obstacleBottom() { _obstacleBottom = true; };
    void obstacleLeft() { _obstacleLeft = true; };
    void obstacleRight() { _obstacleRight = true; };

    void unObstacleTop() { _obstacleTop = false; };
    void unObstacleBottom() { _obstacleBottom = false; };
    void unObstacleLeft() { _obstacleLeft = false; };
    void unObstacleRight() { _obstacleRight = false; };

    bool getTopState() { return _obstacleTop; };
    bool getBottomState() { return _obstacleBottom; };
    bool getLeftState() { return _obstacleLeft; };
    bool getRightState() { return _obstacleRight; };

    void setBlockDirection(BLOCKDIRECTION name) { _dir = name; };
    BLOCKDIRECTION geBlockDirection() { return _dir; };

  private:
    Obstacle();
    bool _obstacleTop, _obstacleBottom, _obstacleLeft, _obstacleRight;
    BLOCKDIRECTION _dir;

    static Obstacle* _instance;
  };

}

#endif // __OBSTACLE_H__
