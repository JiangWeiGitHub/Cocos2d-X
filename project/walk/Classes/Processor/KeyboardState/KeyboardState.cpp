#include "./KeyboardState.h"
#include "./KeyManager.h"

namespace jiangweigithub {

  KeyboardState::KeyboardState()
  {
    obstacle = Obstacle::getInstance();
  }

  KeyboardState::~KeyboardState()
  {
    delete obstacle;
  }

}