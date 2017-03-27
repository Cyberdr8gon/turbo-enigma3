#include "map.h"
#include "enigma_constants.h"


map::map(int x, int y) : xSize(x), ySize(y)
{
  mapLayout = new Tile[y * x];
  for(int i = 0; i < x * y; i++)
  {
    mapLayout[i] = Tile::Unused;
  }
}

map::~map()
{
  delete[] mapLayout;
}

Tile map::getCell(int x, int y)
{
  if ((!(x >> 31) && x < X_MAX_MAP_SIZE) && (!(y >> 31) && y < Y_MAX_MAP_SIZE))
  {
    return mapLayout[x + xSize * y];
  }
  else
  {
    return Tile::InvalidTile;
  }
}

void map::setCell(int x, int y, Tile tileType)
{
  if((!(x>>31) && x < X_MAX_MAP_SIZE) &&(!(y >> 31) && y < Y_MAX_MAP_SIZE))
  {
    mapLayout[x + xSize * y] = tileType;
  } 
}



void map::printDebugMap()
{
  for(int y = 0; y < ySize; y++)
  {
    for(int x = 0; x < xSize; x++)
    {
      switch (getCell(x, y))
      {
      case Unused:
        printf(" ");
        break;
      case Floor:
        printf(".");
        break;
      case Corridor:
        printf(".");
        break;
      case Wall:
        printf("X");
        break;
      case ClosedDoor:
        printf("/");
        break;
      case OpenDoor:
        printf("_");
        break;
      case UpStairs:
        printf("^");
        break;
      case DownStairs:
        printf("v");
        break;
      default:
        printf(".");
        break;
      }
    }

    printf("\n");
  }
}
