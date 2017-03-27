#pragma once
#include <vector>


#include "map.h"
#include "mapSystem.h"
#include "enigma_constants.h"

class gameData
{
    // TODO
  public:
    bool update(std::vector<KeyPressSurfaces> &events);



    

    mapSystem* map_system;
};
