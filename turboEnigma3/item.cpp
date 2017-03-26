// TODO IMPORTANT FOR EVERYONE
// always put system library loads before your library loads to avoid link time errors!!
#include <iostream>

#include "Item.h"

/* TODO IF TIME PERMITS
int Item::itemWeight()
{
	return weight;
}

int Item::itemWear() {
	return wear;
}
*/
int Armor::getProtection() {
	return protection;
}
int Weapon::getDamage() {
	return wDamage;
}