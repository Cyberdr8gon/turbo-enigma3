#pragma once
#include <vector>
#include "../turboEnigma3/Item.h"

// we use unqiue IDs to ensure lookups are fast

class item_table
{
  public:

    item_table();
    
    // just know that if you move/delete this object, it will delete all map data stored within
    // offloaded or not
    ~item_table();
    
    
    // returns unique ID
    int addItemToHero(Item* newItem);
    int addItemToEnemy(Item* newItem);
    int addItemToDropped(Item* newItem, int x, int y);


    // use previously returned unique ID to access item 
    Item* getHeroItem(int uniqueID) const;
    Item* getEnemyItem(int uniqueID) const;
    Item* getDroppedItem(int uniqueID) const;

    // warning, this is a transference of ownership, the reciever is
    // responsible for deleting the memory
    std::vector<Item*>* offloadDroppedItems();
    std::vector<Item*>* offloadEnemyItems();
    std::vector<Item*>* offloadHeroItems();

    // for the hashing to work, it requires that the items handed in are sorted from
    // lowest uniqueID to highest uniqueID
    // the ID's must be contiguous, and if they aren't we should assume that files/memory has been tampered with
    
    // !!!!IMPORTANT!!!!!, you must load data from populate map or a file BEFORE 
    // attempting to access data
    // if you don't comply, THAR BE DRAGONS!!!


    void loadDroppedItems(std::vector<Item*>* sortedItems, int nextUniqueID);
    void loadEnemyItems(std::vector<Item*>* sortedItems, int nextUniqueID);
    void loadHeroItems(std::vector<Item*>* sortedItems, int nextUniqueID);

  private:

    int getNewHeroID();
    int getNewEnemyID();
    int getNewDroppedID();

    int newheroUniqueID = 0;
    int newenemyUniqueID = 0;
    int newdroppedUniqueID = 0;
    
    std::vector<Item*>* _enemyItems;
    std::vector<Item*>* _heroItems;
    std::vector<Item*>* _droppedItems;
};
