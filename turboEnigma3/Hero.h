#pragma once
#include "enigma_constants.h"

class hero
{

public:

  void spawn(int xCord, int yCord);
  int xCord();
  int yCord();

  void moveUp();
  void moveDown();
  void moveLeft();
  void moveRight();

  int _xCord = 0;
  int _yCord = 0;
};
