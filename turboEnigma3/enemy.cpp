#include "enemy.h"

enemy::enemy()
{
	this->health = 100;
}

enemy::enemy(string n)
{
	this->health = 100;
	this->name = n;
}


enemy::~enemy()
{
}

int enemy::getHealth()
{
	return this->health;
}

void enemy::damage(int amount)
{
	this->health -= amount;
}

string enemy::getName()
{
	return this ->name;
}

void enemy::setName(string n)
{
	this->name = n;
}

int enemy::xCord()
{
  return _xCord;
}

int enemy::yCord()
{
  return _yCord;
}
