// TODO IMPORTANT FOR EVERYONE
// always put system library loads before your library loads to avoid link time errors!!
#include <iostream>

#include "Item.h"
/*

** IMPORTANT **
why are we defining these here and in the header? it causes a compile error


Item::Item(int _wear, int _weight)
{
	int wear = _wear;
	int weight = _weight;
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

*/