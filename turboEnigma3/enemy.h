#pragma once

#include <iostream>
#include <string>



class enemy
{
protected:
	int health;
  int attack;
  std::string name;
  int specialClassifier;
  int spriteIndex;
  int _xCord;
  int _yCord;

public:
	enemy(std::string name,int hardness, int hp, int attack, int specialClassifier, int spriteIndex);

	~enemy();

	int adjustHealth();
	int getHealth();
	int damage(int level);
  std::string getName();
	void setName(std::string n);

	bool isAlive(int a);


  int yCord();
  int xCord();

};

