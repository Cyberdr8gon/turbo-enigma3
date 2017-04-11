

#include "item_table.h"

item_table::item_table() : _enemyItems(NULL), _droppedItems(NULL)
{
  
}

item_table::~item_table()
{
  if(_enemyItems)
  {
    for (Item* el : *_enemyItems)
    {
      delete el;
    }
    delete _enemyItems;
  }
  if(_heroItems)
  {
    for (Item* el: *_heroItems)
    {
      delete el;
    }
    delete _heroItems;
  }

  if(_droppedItems)
  {
    for(Item* el : *_droppedItems)
    {
      delete el;
    }
    delete _droppedItems;
  }
}


void item_table::loadDroppedItems(std::vector<Item*>* sortedItems, int nextUniqueID)
{
  if(_droppedItems)
  {
    printf("Item System - Error: loading a non-empty dropped item vector, will likely leak memory\n");
  }

  _droppedItems = sortedItems;
  newdroppedUniqueID = nextUniqueID;
}

void item_table::loadEnemyItems(std::vector<Item*>* sortedItems, int nextUniqueID)
{
  if(_enemyItems)
  {
    
    printf("Item System - Error: loading a non-empty enemy item vector, will likely leak memory\n");
  }

  _enemyItems = sortedItems;
  newenemyUniqueID = nextUniqueID;
}

void item_table::loadHeroItems(std::vector<Item*>* sortedItems, int nextUniqueID)
{
  if (_heroItems)
  {

    printf("Item System - Error: loading a non-empty hero item vector, will likely leak memory\n");
  }

  _enemyItems = sortedItems;
  newenemyUniqueID = nextUniqueID;


}


int item_table::getNewHeroID()
{
  int temp = newheroUniqueID;
  newheroUniqueID++;
  return temp;
}

int item_table::getNewDroppedID()
{
  int temp = newdroppedUniqueID;
  newdroppedUniqueID++;
  return temp;
}

int item_table::getNewEnemyID()
{
  int temp = newenemyUniqueID;
  newenemyUniqueID++;
  return temp;
}

std::vector<Item*>* item_table::offloadDroppedItems()
{
  std::vector<Item*>* temp = _droppedItems;
  _droppedItems = NULL;
  return temp;
}

std::vector<Item*>* item_table::offloadEnemyItems()
{
  std::vector<Item*>* temp = _enemyItems;
  _enemyItems = NULL;
  return temp;

}

std::vector<Item*>* item_table::offloadHeroItems()
{
  std::vector<Item*>* temp = _heroItems;
  _heroItems = NULL;
  return temp;
}

Item* item_table::getHeroItem(int uniqueID) const
{
  return (*_heroItems)[uniqueID];
}

Item* item_table::getDroppedItem(int uniqueID) const
{
  return (*_droppedItems)[uniqueID];
}

Item* item_table::getEnemyItem(int uniqueID) const
{
  return (*_enemyItems)[uniqueID];
}


// TODO check to make these dont cause errors later
// TODO should probably unit test
int item_table::addItemToDropped(Item* newItem, int x, int y)
{
  // location does nothing right now but could be used for optimization later?
  // good to think about, move from O(n) to O(1)
  int newID = getNewDroppedID();
  newItem->setUniqueId(newID);
  (*_droppedItems)[newID] = newItem;

  return newID;
  
}


int item_table::addItemToEnemy(Item* newItem)
{
  int newID = getNewDroppedID();
  newItem->setUniqueId(newID);
  (*_enemyItems)[newID] = newItem;
  return newID;
}

int item_table::addItemToHero(Item* newItem)
{
  int newID = getNewDroppedID();
  newItem->setUniqueId(newID);
  (*_heroItems)[newID] = newItem;
  return newID;
}

