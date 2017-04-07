#pragma once
// TODO important
// on the VC++ compiler ( this one ) and gcc and clang, pragma once does the same thing as header guards, better
#include <iostream>

enum itemTypes {
    Armor,
	Weapon,
	Empty,
	Num_of_Item_Type
};

class Item {
public:
	explicit
		Item();
	itemTypes type;
	// virtual int itemWear(); TODO if time permits
	// virtual int itemWeight(); TODO if time permits
	// virtual void adjustItemWear(Item equipment);
private:
	// int wear;	// wear is damage to item that occurs with use (health of item)
	// int weight;	// impose limit to inventory?
};
class Armor : public Item {
public:
	int protection = 10;
	int getProtection();

};
class Weapon : public Item {
public: 
	int wDamage = 25;
	int getDamage();
};

