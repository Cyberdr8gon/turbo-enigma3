#pragma once
#include <vector>
#include "enemy.h"
#include "Item.h"


enum Tile
{
  Unused = 0,
  Floor,
  Corridor,
  Wall,
  ClosedDoor,
  OpenDoor,
  UpStairs,
  DownStairs,
  TileCount,
  InvalidTile
};

enum Direction
{
  North,
  South,
  East,
  West,
  DirectionCount,
  InvalidDir
};


class map
{
  public:


    map(int x, int y);
    ~map();

    Tile getCell(int x, int y);
    void setCell(int x, int y, Tile tileType);


    void printDebugMap();

    // possibly make a short for more/easier masking options
    Tile* mapLayout;
    int xSize;
    int ySize;

    vector<enemy*> enemyList;
    vector<Item*> itemList;
    
};
