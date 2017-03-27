#include <ctime>
#include "mapGenerator.h"
#include "enigma_constants.h"


int mapGenerator::getRand(int min, int max)
{
  time_t seed;
  seed = time(NULL) + oldseed;
  oldseed = seed;
  
  srand(seed);

  int n = max - min + 1;
  int i = rand() % n;

  if(i < 0)
  {
    i = -i;
  }

  return min + i;
}


bool mapGenerator::makeCorridor(int x, int y, int length, Direction direction)
{
  int len = getRand(2, length);
  Tile floor = Corridor;
  Direction dir = direction;

  int xtemp = 0;
  int ytemp = 0;

  switch (dir)
  {
    case North:
    {
      if(x < 0 || x > X_MAX_MAP_SIZE) return false;
      else xtemp = x;
 
      for(ytemp = y; ytemp > (y-len); ytemp--)
      {
        if(ytemp < 0 || ytemp > Y_MAX_MAP_SIZE) return false;
        if(currentlyGeneratingMap->getCell(xtemp, ytemp) != Unused) return false;
      }
 
      for(ytemp = y; ytemp > (y - len); ytemp--)
      {
        currentlyGeneratingMap->setCell(xtemp, ytemp, floor);
      }
      break;
 
    }
    case 1:
    {
      if(y < 0 || y > Y_MAX_MAP_SIZE) return false;
      else ytemp = y;
 
      for(xtemp = x; xtemp < (x + len); xtemp++)
      {
          if(xtemp < 0 || xtemp > X_MAX_MAP_SIZE) return false;
          if(currentlyGeneratingMap->getCell(xtemp, ytemp) != Unused) return false;
      }
 
      for(xtemp = x; xtemp < (x + len); xtemp++)
      {
          currentlyGeneratingMap->setCell(xtemp, ytemp, floor);
      }
      break;
    }
    case 2:
    {
        if(x < 0 || x > X_MAX_MAP_SIZE) return false;
        else xtemp = x;
 
        for(ytemp = y; ytemp < (y + len); ytemp++)
        {
            if(ytemp < 0 || ytemp > Y_MAX_MAP_SIZE) return false;
            if(currentlyGeneratingMap->getCell(xtemp, ytemp) != Unused) return false;
        }
        for (ytemp = y; ytemp < (y+len); ytemp++){
            currentlyGeneratingMap->setCell(xtemp, ytemp, floor);
        }
			  break;
    }
    case 3:
    {
        if (ytemp < 0 || ytemp > Y_MAX_MAP_SIZE) return false;
        else ytemp = y;
 
        for (xtemp = x; xtemp > (x-len); xtemp--){
            if (xtemp < 0 || xtemp > X_MAX_MAP_SIZE) return false;
            if (currentlyGeneratingMap->getCell(xtemp, ytemp) != Unused) return false;
        }
 
        for (xtemp = x; xtemp > (x-len); xtemp--){
            currentlyGeneratingMap->setCell(xtemp, ytemp, floor);
        }
        break;
    }
  }
	//woot, we're still here! let's tell the other guys we're done!!
	return true;    
}

bool mapGenerator::makeRoom(int x, int y, int xLength, int yLength, Direction direction)
{
  //define the dimensions of the room, it should be at least 4x4 tiles (2x2 for walking on, the rest is walls)
	int xlen = getRand(4, xLength);
	int ylen = getRand(4, yLength);
	//the tile type it's going to be filled with
  Tile floor = Floor;
	Tile wall = Wall;
	//choose the way it's pointing at
	Direction dir = direction;
 
	switch(dir){
	case North:
	//north
		//Check if there's enough space left for it
		for (int ytemp = y; ytemp > (y-ylen); ytemp--){
			if (ytemp < 0 || ytemp > Y_MAX_MAP_SIZE) return false;
			for (int xtemp = (x-xlen/2); xtemp < (x+(xlen+1)/2); xtemp++){
				if (xtemp < 0 || xtemp > X_MAX_MAP_SIZE) return false;
				if (currentlyGeneratingMap->getCell(xtemp, ytemp) != Unused) return false; //no space left...
			}
		}
 
		//we're still here, build
		for (int ytemp = y; ytemp > (y-ylen); ytemp--){
			for (int xtemp = (x-xlen/2); xtemp < (x+(xlen+1)/2); xtemp++){
				//start with the walls
				if (xtemp == (x-xlen/2)) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
				else if (xtemp == (x+(xlen-1)/2)) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
				else if (ytemp == y) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
				else if (ytemp == (y-ylen+1)) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
				//and then fill with the floor
				else currentlyGeneratingMap->setCell(xtemp, ytemp, floor);
			}
		}
		break;
	case 1:
	//east
		for (int ytemp = (y-ylen/2); ytemp < (y+(ylen+1)/2); ytemp++){
			if (ytemp < 0 || ytemp > Y_MAX_MAP_SIZE) return false;
			for (int xtemp = x; xtemp < (x+xlen); xtemp++){
				if (xtemp < 0 || xtemp > X_MAX_MAP_SIZE) return false;
				if (currentlyGeneratingMap->getCell(xtemp, ytemp) != Unused) return false;
			}
		}
 
		for (int ytemp = (y-ylen/2); ytemp < (y+(ylen+1)/2); ytemp++){
			for (int xtemp = x; xtemp < (x+xlen); xtemp++){
 
				if (xtemp == x) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
				else if (xtemp == (x+xlen-1)) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
				else if (ytemp == (y-ylen/2)) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
				else if (ytemp == (y+(ylen-1)/2)) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
 
				else currentlyGeneratingMap->setCell(xtemp, ytemp, floor);
			}
		}
		break;
	case 2:
	//south
		for (int ytemp = y; ytemp < (y+ylen); ytemp++){
			if (ytemp < 0 || ytemp > Y_MAX_MAP_SIZE) return false;
			for (int xtemp = (x-xlen/2); xtemp < (x+(xlen+1)/2); xtemp++){
				if (xtemp < 0 || xtemp > X_MAX_MAP_SIZE) return false;
				if (currentlyGeneratingMap->getCell(xtemp, ytemp) != Unused) return false;
			}
		}
 
		for (int ytemp = y; ytemp < (y+ylen); ytemp++){
			for (int xtemp = (x-xlen/2); xtemp < (x+(xlen+1)/2); xtemp++){
 
				if (xtemp == (x-xlen/2)) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
				else if (xtemp == (x+(xlen-1)/2)) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
				else if (ytemp == y) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
				else if (ytemp == (y+ylen-1)) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
 
				else currentlyGeneratingMap->setCell(xtemp, ytemp, floor);
			}
		}
		break;
	case 3:
	//west
		for (int ytemp = (y-ylen/2); ytemp < (y+(ylen+1)/2); ytemp++){
			if (ytemp < 0 || ytemp > Y_MAX_MAP_SIZE) return false;
			for (int xtemp = x; xtemp > (x-xlen); xtemp--){
				if (xtemp < 0 || xtemp > X_MAX_MAP_SIZE) return false;
				if (currentlyGeneratingMap->getCell(xtemp, ytemp) != Unused) return false;
			}
		}
 
		for (int ytemp = (y-ylen/2); ytemp < (y+(ylen+1)/2); ytemp++){
			for (int xtemp = x; xtemp > (x-xlen); xtemp--){
 
				if (xtemp == x) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
				else if (xtemp == (x-xlen+1)) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
				else if (ytemp == (y-ylen/2)) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
				else if (ytemp == (y+(ylen-1)/2)) currentlyGeneratingMap->setCell(xtemp, ytemp, wall);
 
				else currentlyGeneratingMap->setCell(xtemp, ytemp, floor);
			}
		}
		break;
	}
 
	//yay, all done
	return true;  
}



map* mapGenerator::generateMap(int features, int difficulty)
{
  map* currentlyGeneratingMap = new map(X_MAX_MAP_SIZE, Y_MAX_MAP_SIZE);
  
  makeRoom(X_MAX_MAP_SIZE / 2, Y_MAX_MAP_SIZE / 2, 8, 6, Direction(getRand(0, 3)));

  int currentFeatures = 1;

  for( int countingTries = 0; countingTries < 1000; countingTries++)
  {
    if(currentFeatures == features)
    {
      break;
    }

    int newx = 0;
    int xmod = 0;
    int newy = 0;
    int ymod = 0;
    Direction validTile = InvalidDir;

    for (int testing = 0; testing < 1000; testing++)
    {
      newx = getRand(1, X_MAX_MAP_SIZE - 1);
      newy = getRand(1, Y_MAX_MAP_SIZE - 1);
      validTile = InvalidDir;
      if (currentlyGeneratingMap->getCell(newx, newy) == Wall 
          || currentlyGeneratingMap->getCell(newx, newy) == Corridor)
      {
        if(currentlyGeneratingMap->getCell(newx, newy + 1) == Wall 
            || currentlyGeneratingMap->getCell(newx, newy + 1) == Corridor)
        {
          validTile = North;
          xmod = 0;
          ymod = -1;
        }
        else if (currentlyGeneratingMap->getCell(newx - 1, newy) == Wall 
                || currentlyGeneratingMap->getCell(newx - 1, newy) == Corridor)
        {
          validTile = East;
          xmod = 1;
          ymod = 0;
        }
        else if (currentlyGeneratingMap->getCell(newx, newy - 1) == Wall 
                || currentlyGeneratingMap->getCell(newx, newy - 1) == Corridor)
        {
          validTile = South;
          xmod = 0;
          ymod = 1;
          
        } 
        else if (currentlyGeneratingMap->getCell(newx + 1, newy) == Wall 
                || currentlyGeneratingMap->getCell(newx + 1, newy) == Corridor)
        {
          validTile = West;
          xmod = -1;
          ymod = 0;
        }

        if(validTile != InvalidDir)
        {
          if(currentlyGeneratingMap->getCell(newx, newy + 1) == ClosedDoor 
            || currentlyGeneratingMap->getCell(newx, newy + 1) == OpenDoor)
          {
            validTile = InvalidDir;
          }
          else if (currentlyGeneratingMap->getCell(newx - 1, newy) == ClosedDoor 
            || currentlyGeneratingMap->getCell(newx - 1, newy) == OpenDoor)
          {
            validTile = InvalidDir;
          }
          else if (currentlyGeneratingMap->getCell(newx + 1, newy) == ClosedDoor 
            || currentlyGeneratingMap->getCell(newx + 1, newy) == OpenDoor)
          {
            validTile = InvalidDir;
          }
          else if (currentlyGeneratingMap->getCell(newx, newy - 1) == ClosedDoor 
            || currentlyGeneratingMap->getCell(newx, newy - 1) == OpenDoor)
          {
            validTile = InvalidDir;
          }
        }

        if(validTile != InvalidDir)
        {
          break;
        }
      }
    }

    if(validTile > -1)
    {
      int feature = getRand(0, 100);

      if(feature <= chanceRoom )
      {
        if(makeRoom((newx + xmod), (newy + ymod), 8, 6, validTile))
        {
          // increment features
          currentFeatures++;
          // randomly choose open or closed door
          bool openOrClosed = bool(getRand(0, 10) % 2);
          // mark wall opening with door
          currentlyGeneratingMap->setCell(newx, newy, openOrClosed ? OpenDoor : ClosedDoor);

          // clean up in front of door so we can always reach it
          currentlyGeneratingMap->setCell((newx + xmod), (newy + ymod), Floor);

        }
        else if (feature >= chanceRoom)
        {
          if(makeCorridor((newx+xmod), (newy + ymod), 6, validTile))
          {
            // increment features
            currentFeatures++;

            // randomly choose open or closed door
            bool openOrClosed = bool(getRand(0, 10) % 2);
            // mark wall opening with door
            currentlyGeneratingMap->setCell(newx, newy, openOrClosed ? OpenDoor : ClosedDoor);
          }
        }
      }
    }

  }


  populateMap(currentlyGeneratingMap, difficulty);

  map* tempMapVar = currentlyGeneratingMap;
  currentlyGeneratingMap = NULL;
  return tempMapVar;
}

void mapGenerator::populateMap(map* mapToPopulate, int difficulty)
{
  // TODO this is important
  // minimum needed is the stairs up and down
}
