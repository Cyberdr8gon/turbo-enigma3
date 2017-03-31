#pragma once
#include "map.h"

// collision handling functions

// returns:
// 0 is can walk
// 1 is cant walk
// 2 is toggle door
int canWalk(Tile tileToCheck);
