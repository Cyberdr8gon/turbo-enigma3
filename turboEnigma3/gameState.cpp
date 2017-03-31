#include <vector>

#include "gameState.h"
#include "collision.h"


// eventually check game type (inventory/menu/etc)
bool gameData::update(std::vector<KeyPressSurfaces> &events)
{
  while(!events.empty())
  {
    KeyPressSurfaces _event = events.back();
    events.pop_back();


    switch (_event) {
      case KEY_PRESS_SURFACE_UP:
      {
        int result = canWalk(map_system->loadedLevels[2]->getTile(heroEntity->xCord(),
          heroEntity->yCord() - 1));
        if (!result)
        {
          heroEntity->moveDown();
        } else if (result == 2)
        {
          map_system->loadedLevels[2]->setTile(heroEntity->xCord(), heroEntity->yCord() - 1, OpenDoor);
        }
        break;
      }
      case KEY_PRESS_SURFACE_DOWN:
      {
        int result = canWalk(map_system->loadedLevels[2]->getTile(heroEntity->xCord(),
          heroEntity->yCord() + 1));
        if (!result)
        {
          heroEntity->moveUp();
        } else if(result == 2)
        {
          map_system->loadedLevels[2]->setTile(heroEntity->xCord(), heroEntity->yCord() + 1, OpenDoor);
        }
        break;
      }

      case KEY_PRESS_SURFACE_RIGHT:
      {
        int result = canWalk(map_system->loadedLevels[2]->getTile(heroEntity->xCord() + 1,
          heroEntity->yCord()));
        if (!result)
        {
          heroEntity->moveRight();
        } else if (result == 2)
        {
          map_system->loadedLevels[2]->setTile(heroEntity->xCord() + 1, heroEntity->yCord(), OpenDoor);
        }
        break;
      } 

      case KEY_PRESS_SURFACE_LEFT:
      {
        int result = canWalk(map_system->loadedLevels[2]->getTile(heroEntity->xCord() - 1,
          heroEntity->yCord()));
        if (!result)
        {
          heroEntity->moveLeft();
        } else if (result == 2)
        {
          map_system->loadedLevels[2]->setTile(heroEntity->xCord() - 1, heroEntity->yCord(), OpenDoor);
        }
        break;
      } 
    }
  }

  return true;
}


gameData::gameData()
{
  map_system = new mapSystem();
  heroEntity = new hero();
}
