// TODO IMPORTANT FOR EVERYONE
// always put system library loads before your library loads to avoid link time errors!!
#include "Item.h"

/* TODO add back in time premiting
int Item::itemWeight()
{
	return weight;
}
*/

int Item::itemWear() const
{
	return _wear;
}

Item::Item(int UniqueId, itemTypes type, int wear, std::string name)
  : _type(type), _uniqueID(UniqueId), _wear(wear), _itemName(name), _equipState(Unequipped)
{
}


void Item::updateEquipState(itemEquipState isEquipped)
{
  _equipState = isEquipped;
}


itemEquipState Item::isItemEquiped() const
{
  return _equipState;
}

std::string Item::getName() const
{
  return _itemName;
}

Armor::Armor(int UniqueId, int wear, int protection, std::string name) 
: Item(UniqueId, itemTypes::Armor, wear, name) , _protection(protection)
{
  
}


int Armor::getProtection() const
{
	return _protection;
}


Weapon::Weapon(int UniqueId, int wear, int damage, std::string name)
              : Item(UniqueId, itemTypes::Weapon, wear, name), _wDamage(damage)
{
  
}


int Weapon::getDamage() const
{
	return _wDamage;
}

int Item::getUniqueId() const
{
  return _uniqueID;
}

void Item::setUniqueId(int ID)
{
  _uniqueID = ID;
}
