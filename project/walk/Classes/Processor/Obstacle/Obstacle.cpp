#include "./Obstacle.h"

namespace jiangweigithub {

  Obstacle::Obstacle()
  {
    _obstacleTop = false;
    _obstacleBottom = false;
    _obstacleLeft = false;
    _obstacleRight = false;

    _dir = NONE;
  }

  Obstacle::~Obstacle()
  {
    _obstacleTop = false;
    _obstacleBottom = false;
    _obstacleLeft = false;
    _obstacleRight = false;
    
    _dir = NONE;
  }

  Obstacle* Obstacle::_instance = new Obstacle();
  Obstacle* Obstacle::getInstance()
  {
    return _instance;
  }

}