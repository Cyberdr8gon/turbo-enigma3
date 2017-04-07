#include "enemy.h"
#include "hero.h"

enemy::enemy()
{
	health = 100;
}

enemy::enemy(string n)
{
	health = 100;
	name = n;
}




enemy::~enemy()
{
}

/*
void enemy::adjustHealth()
{
	int hdmg = hero::damage();
	int health = this-> health;
	int newHealth = health - hdmg;
	if ((newHealth - health) > 0)
	{
		this->health -= hdmg;
	}
	else
		isAlive(0);
}
*/

int enemy::getHealth()
{
	return health;
}

int enemy::damage(int level)
{
	int attackDamage = 10;
	return attackDamage;
}

string enemy::getName()
{
	return name;
}

void enemy::setName(string n)
{
	name = n;
}

int enemy::xCord()
{
  return _xCord;
}

int enemy::yCord()
{
  return _yCord;
}
bool isAlive(int a)
{
	if (a == 1)
		return 1;
	else
		return 0;
}


