#pragma once
#include <vector>


#include "map.h"
#include "mapSystem.h"
#include "enigma_constants.h"
#include "Hero.h"
#include "../gameCodeLib/enemy_library.h"

class gameData
{
    // TODO
  public:
    bool update(std::vector<KeyPressSurfaces> &events);


    gameData();
    
    hero* heroEntity;

    mapSystem* map_system;

    enemy_library enemy_lib;
    
};
