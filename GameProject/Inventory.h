#pragma once

#include "Item.h"
#include "Armor.h"
#include "Sword.h"
#include "Pendant.h"

class Inventory
{
	static const int INVENTORY_CAPACITY = 3;

	Item** items;
	size_t itemsCount;

public:
	Inventory();
	~Inventory();

	size_t getItemsCount() const;
	void addItem(const char);
	void printInventory() const;

	Item* getItemAtPos(size_t);

	void save(std::ofstream&) const;
	void load(std::ifstream&);
private:
	void allocateMemory();
	void freeMemory();
private:
	Inventory(const Inventory&); //not implemented
	Inventory& operator=(const Inventory&); //not implemented
};