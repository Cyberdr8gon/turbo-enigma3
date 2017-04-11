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

enum itemEquipState
{
  EnemyEquipped,
  PlayerEquipped,
  Unequipped,
  numOfEquipStates
};

class Item {
public:
	explicit
	Item(int UniqueId,itemTypes type, int wear, std::string name);
	itemTypes _type;
	int itemWear() const; 

  // getter and setter for equip state
  void updateEquipState(itemEquipState isEquipped);
  itemEquipState isItemEquiped() const;

  // getter for item name
  std::string getName() const;

  int getUniqueId() const;
  void setUniqueId(int ID);

	// virtual int itemWeight(); TODO if time permits
	// virtual void adjustItemWear(Item equipment);
private:
  int _uniqueID;
	int _wear;	// wear is damage to item that occurs with use (health of item)
  std::string _itemName;
  itemEquipState _equipState;
	// int weight;	// impose limit to inventory?
};

class Armor : public Item {
public:

  Armor(int UniqueId, int wear, int protection, std::string name);

	int _protection;
	int getProtection() const;

};

class Weapon : public Item {
public: 
  Weapon(int UniqueId, int wear, int damage, std::string name);
	int _wDamage;
	int getDamage() const;
};

