#pragma once
#include "map.h"


// there is more work to do here, but I want to get rendering running
class mapSystem
{
  public:


    // later we should add utilities to offload levels to disk if they are too far
    // away to avoid filling all of memory in a long game and to begin the 
    // process of creating a save format

    bool generateNewFloor(int difficulty);

    mapSystem();
    ~mapSystem();

    void upFloor();
    void downFloor();

    int currentFloor;
    int totalFloors;
    // index 2 is ALWAYS the current floor
    map* loadedLevels[5];

};
