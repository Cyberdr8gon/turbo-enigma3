#include <vector>

#include "gameState.h"


bool gameData::update(std::vector<KeyPressSurfaces> &events)
{
    return true;
}


gameData::gameData()
{
  map_system = new mapSystem();
  heroEntity = new hero();
}
