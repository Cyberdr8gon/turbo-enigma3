#include "enemy_library.h"
#include <fstream>
#include <sstream>
#include "../turboEnigma3/enigma_constants.h"


enemy_library::enemy_library() : rd(), rng(rd())
{
  std::ifstream fileHandle("enemies/manifest.txt");
  
  std::string line;
  std::vector<std::string> filesToLoad;

  if(!fileHandle)
  {
    printf("Enemy Generation - Error: Couldn't find manifest.txt");
    exit(5);
  }

  enemy_prototypes temp;
  while(std::getline(fileHandle, line))
  {
    std::stringstream linestream(line);
    std::string cell;
    if(std::getline(linestream, cell, ','))
    {
      temp.name = cell;
      std::getline(linestream, cell, ',');
      temp._baseAttack = atoi(cell.c_str());
      std::getline(linestream, cell, ',');
      temp._baseDifficulty = atoi(cell.c_str());
      std::getline(linestream, cell, ',');
      temp._baseHP = atoi(cell.c_str());
      std::getline(linestream, cell, ',');
      temp._specialClassifer = atoi(cell.c_str());
      std::getline(linestream, cell, ',');
      temp._spriteIndex = atoi(cell.c_str());
      _prototypes.push_back(temp);

    }
  }
}

enemy* enemy_library::generateEnemy(int desiredHardness)
{
  std::normal_distribution<int> norm(desiredHardness, 2);

  int randomInt = norm(rng);

  if(randomInt > MAX_ENEMY_DIFFICULTY)
  {
    randomInt = MAX_ENEMY_DIFFICULTY;
  }

  std::vector<enemy_prototypes> tempEnemyPrototypes;
  enemy_prototypes enemyToProduce;
  for(enemy_prototypes el : _prototypes)
  {
    if(el._baseDifficulty == randomInt)
    {
      tempEnemyPrototypes.push_back(el);
    }
  }

  if(tempEnemyPrototypes.empty())
  {
    std::uniform_int_distribution<int> uniformDist(0, _prototypes.size() - 1);
    enemyToProduce = _prototypes[uniformDist(rng)];

  } else
  {
    std::uniform_int_distribution<int> uniformDist(0, tempEnemyPrototypes.size());
    enemyToProduce = tempEnemyPrototypes[uniformDist(rng)];
  }

  // might want to do more with names here later
  std::normal_distribution<int> health(enemyToProduce._baseHP, 6);
  std::normal_distribution<int> attack(enemyToProduce._baseAttack, 6);
  return new enemy(enemyToProduce.name, randomInt, health(rng), attack(rng), enemyToProduce._specialClassifer, enemyToProduce._spriteIndex);
}

