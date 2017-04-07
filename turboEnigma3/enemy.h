#pragma once

#include <iostream>
#include <string>

using namespace std;


class enemy
{
protected:
	int health;
	string name;
  int _xCord;
  int _yCord;

public:
	enemy();
	enemy(string n);

	~enemy();

	int adjustHealth();
	int getHealth();
	int damage(int level);
	string getName();
	void setName(string n);

	bool isAlive(int a);


  int yCord();
  int xCord();

};

