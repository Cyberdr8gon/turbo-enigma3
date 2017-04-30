#include "collision.h"


// eventually add entity and item checking 
int canWalk(Tile tileToCheck)
{
  
  if(tileToCheck == Floor || tileToCheck == Corridor || OpenDoor == tileToCheck)
  {
    return 0;
  }
  else if(tileToCheck == ClosedDoor)
  {
    return 2;
  }
  else if(tileToCheck == Wall)
  {
    return 1;
  }

  return -1;
}

int selectWallTile(Tile up, Tile down, Tile right, Tile left)
{
  if(
     (right == Tile::Wall) && 
     (down  == Tile::Wall) && 
     (left  != Tile::Wall) &&
     (up != Tile::Wall)) 
  {
    return 8;
  } else if (
     ( right != Tile::Wall) && 
     ( down  == Tile::Wall) && 
     ( left  == Tile::Wall) &&
     ( up != Tile::Wall)) 
  {
    return 9;
  } else if (
     (right == Tile::Wall) && 
     (down  != Tile::Wall) && 
     (left  != Tile::Wall) &&
     (up    == Tile::Wall)) 
  {
    return 10;
  } else if (
     ( right != Tile::Wall) && 
     ( down  != Tile::Wall) && 
     ( left  == Tile::Wall) &&
     ( up    == Tile::Wall)) 
  {
    return 11;
  } else if (
     (right == Tile::Wall) && 
     (down  != Tile::Wall) && 
     (left  != Tile::Wall) &&
     (up    != Tile::Wall)) 
  {
    return 12;
  } else if (
     (right == Tile::Wall) && 
     (down  != Tile::Wall) && 
     (left  == Tile::Wall) &&
     (up    != Tile::Wall)) 
  {
    return 13;
  } else if (
     (right != Tile::Wall) && 
     (down  != Tile::Wall) && 
     (left  == Tile::Wall) &&
     (up    != Tile::Wall)) 
  {
    return 14;
  } else if (
     (right == Tile::Wall) && 
     (down  == Tile::Wall) && 
     (left  == Tile::Wall) &&
     (up    == Tile::Wall)) 
  {
    return 15;
  } else if (
     (right != Tile::Wall) && 
     (down  != Tile::Wall) && 
     (left  != Tile::Wall) &&
     (up    == Tile::Wall)) 
  {
    return 16;
  } else if (
     (right != Tile::Wall) && 
     (down  == Tile::Wall) && 
     (left  != Tile::Wall) &&
     (up    == Tile::Wall)) 
  {
    return 17;
  } else if (
     (right != Tile::Wall) && 
     (down  == Tile::Wall) && 
     (left  != Tile::Wall) &&
     (up    != Tile::Wall)) 
  {
    return 18;
  } else if (
     (right != Tile::Wall) && 
     (down  == Tile::Wall) && 
     (left  == Tile::Wall) &&
     (up    == Tile::Wall)) 
  {
    return 19;
  } else if (
     (right == Tile::Wall) && 
     (down  == Tile::Wall) && 
     (left  != Tile::Wall) &&
     (up    == Tile::Wall)) 
  {
    return 20;
  } else if (
     (right == Tile::Wall) && 
     (down  != Tile::Wall) && 
     (left  == Tile::Wall) &&
     (up    == Tile::Wall)) 
  {
    return 21;
  } else if (
     (right == Tile::Wall) && 
     (down  == Tile::Wall) && 
     (left  == Tile::Wall) &&
     (up    != Tile::Wall)) 
  {
    return 22;
  } else {
    return 1;
  }


}
