#include "enemy.h"
#include "hero.h"

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


void enemy::adjustHealth(int damage)
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

int enemy::getHealth()
{
	return this->health;
}

int enemy::damage(int level)
{
	int attackDamage = 10;
	return attackDamage;
}

string enemy::getName()
{
	return this ->name;
}

void enemy::setName(string n)
{
	this->name = n;
}

bool isAlive(int a)
{
	if (a == 1)
		return 1;
	else
		return 0;
}


