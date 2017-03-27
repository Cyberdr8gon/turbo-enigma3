#pragma once
#include "map.h"

class mapGenerator
{

  public:

    map* generateMap(int features, int difficulty);

private:
    int getRand(int min, int max);

    void populateMap(map* mapToPopulate, int difficulty);
    
    bool makeCorridor(int x, int y, int length, Direction direction);
    bool makeRoom(int x, int y, int xLength, int yLength, Direction direction);



    long oldseed = 0;

    int chanceRoom = 75;
    int chanceCorridor = 25;

    // should always be null unless a gen is in progress
    map* currentlyGeneratingMap = NULL;


};