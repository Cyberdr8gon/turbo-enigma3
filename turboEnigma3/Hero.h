#pragma once
#include "enigma_constants.h"

class hero
{

public:
  int xCord();
  int yCord();

  int _xCord = X_MAX_MAP_SIZE / 2;
  int _yCord = Y_MAX_MAP_SIZE / 2;
};
