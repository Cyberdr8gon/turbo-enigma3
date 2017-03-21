#include "Item.h"
#include <iostream>

Item::Item(int wear, int weight)
{
	int wear = wear;
	int weight = weight;
};

class Light_Armor : public Item {
};

class Heavy_Armor : public Item {
};

class Short_sword : public Item {
};

class Long_sword : public Item {
};

class Bow : public Item {
};