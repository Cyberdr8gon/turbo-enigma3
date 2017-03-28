#pragma once
#include "enemy.h"


struct entity_linked_obj
{
  enemy* containedEnemy = NULL;
  entity_linked_obj* nextObj = NULL;
};

// TODO this class should really be refactored at some point to avoid errors I might have made
class entity_table
{
  // eventually implement balancing and rehashing if linked list depth gets too large
public:
  entity_table(int initialArraySize);
  ~entity_table();

  // returns null if coordinate is empty
  enemy* getEntity(int x, int y);
  void addEntity(int x, int y, enemy* entity);
  bool moveEntity(int oldX, int oldY, int newX, int newY);
  // returns removed entity
  // returns null if coordinate is empty
  enemy* removeEntity(int x, int y);
  


private:
  int hashingFunction(int x, int y) const;
  // dynamically allocate memory for the enemy and the 
  void addToList(int hash, enemy* entity);
  void addToList(entity_linked_obj* currentObj, enemy* entity);
  bool isEntity(int x, int y, entity_linked_obj* entityObj);

  int _sizeOfArray;
  int _numberOfElements;
  entity_linked_obj** hashTable;
};
