#pragma once
#include "map.h"


class mapSystem
{
  public:


    // later we should add utilities to offload levels to disk if they are too far
    // away to avoid filling all of memory in a long game and to begin the 
    // process of creating a save format

    bool generateNewFloor(int difficulty);


    int currentFloor;
    int totalFloors;
    map* loadedLevels[5];

};
