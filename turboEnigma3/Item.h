#pragma once
#ifndef ITEM_H
#define ITEM_H

#include <iostream>

class Item {
public:
	explicit
		Item(int wear, int weight);
	virtual int itemWear() {
		return wear;
	}
	virtual int itemWeight() {
		return weight;
	}
private:
	int wear;	// wear is damage to item that occurs with use (health of item)
	int weight;	// impose limit to inventory?

};

class Light_Armor : public Item {
public:
	Light_Armor(int wear, int weight, int protection)
		: Item(wear, weight) {};
	int itemProtection() {
		return protection;
	}
	int itemWeight();
	int itemWear();
private:
	int protection;	// number of damage points absorbed, influenced by Item wear
};

class Heavy_Armor : public Item {
public:
	Heavy_Armor(int wear, int weight, int protection)
		: Item(wear, weight) {};
	int itemProtection() {
		return protection;
	}
	int itemWeight();
	int itemWear();
private:
	int protection;
};

class Short_Sword : public Item {
public:
	Short_Sword(int wear, int weight, int damage, int range)
		: Item(wear, weight) {};
	int weaponDamage();
	int weaponRange();
	int itemWeight();
	int itemWear();
private:
	int damage;	// damage points inflicted by weapon
	int range;	// distance from object before damage inflicted
};

class Long_Sword : public Item {
public:
	Long_Sword(int wear, int weight, int damage, int range)
		: Item(wear, weight) {};
	int weaponDamage();
	int weaponRange();
	int itemWeight();
	int itemWear();
private:
	int damage;	// damage points inflicted by weapon
	int range;	// distance from object before damage inflicted
};

class Bow : public Item {
public:
	Bow(int wear, int weight, int damage, int range)
		: Item(wear, weight) {};
	int weaponDamage();
	int weaponRange();
	int itemWeight();
	int itemWear();
private:
	int damage;	// damage points inflicted by weapon
	int range;	// distance from object before damage inflicted
};

#endif
