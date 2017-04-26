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
}
