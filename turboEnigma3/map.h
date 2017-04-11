#pragma once
#include <vector>
#include "enemy.h"
#include "Item.h"
#include "entity_table.h"
#include "../gameCodeLib/item_table.h"


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

struct Rect
{
  int x;
  int y;
  int width;
  int height;
};

class map
{
  public:


    map(int width, int height);

    void generate(int maxFeatures, int difficulty);

    void printDebugMap();

    Tile getTile(int x, int y) const;

    void setTile(int x, int y, Tile tileType);

    int getDownStairX();
    int getDownStairY();
    int getUpStairX();
    int getUpStairY();
  private: 

    std::string getTileString(int x, int y);


    bool createFeature();
    bool createFeature(int x, int y, Direction dir);

    bool makeRoom(int x, int y, Direction dir, bool firstRoom = false);

    bool makeCorridor(int x, int y, Direction dir);

    bool placeRect(const Rect& rect, Tile tile);

    bool placeObject(Tile tile);

    bool placeUpStairs();
    bool placeDownStairs();

    void populate(int difficulty);


  private:
    entity_table _enemyTable;
    item_table _itemList;
    
    int _width;
    int _height;

    int _upStairsX;
    int _upStairsY;

    int _downStairsX;
    int _downStairsY;

    std::vector<Tile> _tiles;
    std::vector<Rect> _rooms;
    std::vector<Rect> _exits;
};
