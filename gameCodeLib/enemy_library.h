#pragma once
#include <vector>
#include "../turboEnigma3/enemy.h"
#include <random>

struct enemy_prototypes
{
  std::string name;
  int _baseDifficulty;
  int _baseAttack;
  int _baseHP;
  // identifies the monster's code to be executed
  // there will be generic attack classes as well
  int _specialClassifer;
  int _spriteIndex;
};


// Sample manifest:
/*
 * Crawler,5,2,2
 * Slime,1,1,1
 *
 *
 *
 */

class enemy_library
{
  public:
    enemy_library();

    enemy* generateEnemy(int desiredHardness);

    int _numOfAvalibleEnemies;
    std::vector<enemy_prototypes> _prototypes;
    std::random_device rd;
    std::mt19937 rng;
    
};
