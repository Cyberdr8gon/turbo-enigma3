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

    void generate(int maxFeatures);

    void printDebugMap();

  private: 
    Tile getTile(int x, int y) const;
    void setTile(int x, int y, Tile tileType);

    std::string getTileString(int x, int y);


    bool createFeature();
    bool createFeature(int x, int y, Direction dir);

    bool makeRoom(int x, int y, Direction dir, bool firstRoom = false);

    bool makeCorridor(int x, int y, Direction dir);

    bool placeRect(const Rect& rect, Tile tile);

    bool placeObject(Tile tile);



  private:
    // possibly make a short for more/easier masking options
    vector<enemy*> enemyList;
    vector<Item*> itemList;
    
    int _width;
    int _height;
    std::vector<Tile> _tiles;
    std::vector<Rect> _rooms;
    std::vector<Rect> _exits;
};
