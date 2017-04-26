#include "mapSystem.h"
#include "enigma_constants.h"

mapSystem::mapSystem() : currentFloor(1), totalFloors(3)
{
  loadedLevels[2] = new map(X_MAX_MAP_SIZE, Y_MAX_MAP_SIZE);
  loadedLevels[3] = new map(X_MAX_MAP_SIZE, Y_MAX_MAP_SIZE);
  loadedLevels[4] = new map(X_MAX_MAP_SIZE, Y_MAX_MAP_SIZE);
  loadedLevels[2]->generate(1000, 1);
  loadedLevels[3]->generate(1000, 2);
  loadedLevels[4]->generate(1000, 3);

}

mapSystem::~mapSystem()
{
  for(int i = 0; i < 5; i++)
  {
    delete loadedLevels[i];
  }

  
}



bool mapSystem::generateNewFloor(int difficulty)
{
  loadedLevels[4] = new map(X_MAX_MAP_SIZE, Y_MAX_MAP_SIZE);
  loadedLevels[4]->generate(1000, difficulty);
  totalFloors++;
  return true;
}

void mapSystem::upFloor()
{
  // TODO implement saving function for oldest floor
  // this delete is only temporary
  delete loadedLevels[0];
  for(int i = 1; i < 5; i++)
  {
    loadedLevels[i - 1] = loadedLevels[i];
  }
  currentFloor++;
  generateNewFloor(currentFloor + 2);
}

void mapSystem::downFloor()
{
  // TODO implement saving function for highest floor
  // NOTE KYLEE this is where you should put your saving utilities
}
