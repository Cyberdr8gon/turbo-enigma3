#pragma once

#include <iostream>
#include <string>

using namespace std;


class enemy
{
protected:
	int health;
	string name;

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
};

