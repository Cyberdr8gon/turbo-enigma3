#include "entity_table.h"
#include "enigma_constants.h"
#include <vector>


entity_table::entity_table(int initialArraySize)
{
  _sizeOfArray = initialArraySize;
  _numberOfElements = 0;
  hashTable = new entity_linked_obj*[initialArraySize];
  for(int i = 0; i < initialArraySize; i++)
  {
    hashTable[i] = NULL;
  }
}

entity_table::~entity_table()
{
  // this could take some testing XD
  std::vector<entity_linked_obj*> objToDelete;
  for(int i = 0; i < _sizeOfArray; i++)
  {
    if(hashTable[i])
    {
      entity_linked_obj* temp = hashTable[i];
      while(temp)
      {
        objToDelete.push_back(temp);
        temp = temp->nextObj;
      }
    }
  }

  for (entity_linked_obj* el : objToDelete)
  {
    delete el->containedEnemy;
    delete el;
  }

  delete[] hashTable;
}

void entity_table::addEntity(int x, int y, enemy* entity)
{
  // ensure valid coordinate
  if (x >= 0 && x < X_MAX_MAP_SIZE && y >= 0 && y < Y_MAX_MAP_SIZE) {
    addToList(hashingFunction(x, y), entity);
  }

}

void entity_table::addToList(int hash, enemy* entity)
{
  entity_linked_obj* currentEntityPtr = hashTable[hash];
  
  // check if bucket is empty
  if(currentEntityPtr == NULL)
  {
    entity_linked_obj* tempObj = new entity_linked_obj;
    tempObj->containedEnemy = entity;
    hashTable[hash] = tempObj;
    return;
  }

  // if not, iterate list until it finds a empty list
  addToList(currentEntityPtr, entity);



}

void entity_table::addToList(entity_linked_obj* currentObj, enemy* entity)
{
  if(currentObj->nextObj == NULL)
  {
    entity_linked_obj* tempNode = new entity_linked_obj;
    tempNode->containedEnemy = entity;
    currentObj->nextObj = tempNode;
    return;
  }
  else
  {
    addToList(currentObj->nextObj, entity);
  }
}


enemy* entity_table::getEntity(int x, int y)
{
  entity_linked_obj* currentObj = hashTable[hashingFunction(x, y)];
  // if empty bucket
  if(!currentObj)
  {
    return NULL;
  }
  else
  {
    // if we found it first try, return enemy
    if(isEntity(x,y,currentObj))
    {
      return currentObj->containedEnemy;
    } else
    {
      
      // iterate linked list looking for enemry
      while(currentObj && !isEntity(x, y, currentObj))
      {
        currentObj = currentObj->nextObj;
      }
      // if the current object is still not null, return
      if(currentObj)
      {
        return currentObj->containedEnemy;
      }
    }
  }
  // it wasn't there :(
  return NULL;
}

bool entity_table::isEntity(int x, int y, entity_linked_obj* entityObj)
{
  if (entityObj) {
    if (entityObj->containedEnemy)
    {
      if (entityObj->containedEnemy->xCord() == x
        && entityObj->containedEnemy->yCord() == y)
      {
        return true;
      }
    }
    return false;
  }
  else
  {
    printf("Error - Entity System: Tried to access invalid entity object in hash table\n");
  }
}

int entity_table::hashingFunction(int x, int y) const
{
  int temp = ((x + y) * x) % _sizeOfArray;
  if(temp >= 0)
  {
    return temp;
  }
  else
  {
    return -temp;
  }
}


enemy* entity_table::removeEntity(int x, int y)
{
  if (getEntity(x, y))
  {
    entity_linked_obj* temp = hashTable[hashingFunction(x, y)];
    // if the bucket contains the entity on the first try
    // replace it on the list by shifting the list (even if empty) up
    // then delete the node
    if(isEntity(x,y,temp))
    {
      hashTable[hashingFunction(x, y)] = temp->nextObj;
      enemy* deletedEnemy = temp->containedEnemy;
      delete temp;
      return deletedEnemy;
    }
    // else the item is down the linked list
    entity_linked_obj* oldTemp = NULL;
    while(temp && !isEntity(x,y,temp))
    {
      oldTemp = temp;
      temp = temp->nextObj;
    }
    if(temp)
    {
      oldTemp->nextObj = temp->nextObj;
      enemy* deletedEnemy = temp->containedEnemy;
      delete temp;
      return deletedEnemy;
    }
  }
  // failed to find
  return NULL;
}

bool entity_table::moveEntity(int oldX, int oldY, int newX, int newY)
{
  enemy* enemy = removeEntity(oldX, oldY);
  if(enemy)
  {
    addEntity(newX, newY, enemy);
    return true;
  }
  return false;
}
