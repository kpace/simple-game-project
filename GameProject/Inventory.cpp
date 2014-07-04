#include <iostream>
#include "Inventory.h"

Inventory::Inventory()
{
	this->itemsCount = 0;
	this->items = NULL;
	allocateMemory();
}

Inventory::~Inventory()
{
	freeMemory();
}

// Allocates memory for items

void Inventory::allocateMemory()
{
	try
	{
		this->items = new Item* [INVENTORY_CAPACITY];
	}
	catch(std::bad_alloc&)
	{
		freeMemory();
		throw;
	}

	for(int i = 0; i < INVENTORY_CAPACITY; i++)
		items[i] = NULL;
}

// Frees the memory occupied by items

void Inventory::freeMemory()
{
	if(items != NULL)
	{
		for(size_t i = 0; i < itemsCount; i++)
		{
			if(items[i] != NULL)
				delete items[i];
		}
		delete [] items;
	}
	itemsCount = 0;
}

// Returns how many items inventory has

size_t Inventory::getItemsCount() const
{
	return this-> itemsCount;
}

// Adds new item in the end of items array

void Inventory::addItem(const char c)
{
	try
	{
		if(itemsCount < INVENTORY_CAPACITY)
		{
			switch(c)
			{
			case 'A' :
				{
					items[itemsCount] = new Armor();
					itemsCount++;
					break;
				}
			case 'S' : 
				{
					items[itemsCount] = new Sword();
					itemsCount++;
					break;
				}
			case 'P' :
				{
					items[itemsCount] = new Pendant();
					itemsCount++;
					break;
				}
			}
			std::cout << "\nYou have new item.\n\n";
			system("PAUSE");
		}
		else
		{
			std::cout << "\nInventory is full."
				<< " You wasted this item.\n";
			system("PAUSE");
		}
	}
	catch(std::bad_alloc&)
	{
		std::cout << "Problem with memory. The item is not added.\n";
	}
}

// Prints the items of the inventory

void Inventory::printInventory() const
{
	if(getItemsCount() > 0)
	{
		std::cout << "\nItems you have:\n";

		for(size_t i = 0; i < itemsCount; i++)
		{
			std::cout << items[i]->toString() << " ";
		}
	}
	else
	{
		std::cout << "\n\nInventory is empty\n";
	}
}

// Returns pointer to item at given position
// (returns NULL of the position is not valid)

Item* Inventory::getItemAtPos(size_t pos)
{
	if(pos >= 0 && pos < itemsCount)
		return items[pos];
	else
		return NULL;
}

// Saves inventory in binary file 

void Inventory::save(std::ofstream& ofs) const
{
	ofs.write((char*) &itemsCount, sizeof(itemsCount));

	for(size_t i = 0; i < itemsCount; i++)
	{
		char symbol = items[i]->getSymbol();
		ofs.write((char*) &symbol, sizeof(symbol));
	}
}

// Reads inventory from binary file

void Inventory::load(std::ifstream& ifs)
{
	freeMemory();
	allocateMemory();

	size_t itemsToLoad;

	ifs.read((char*) &itemsToLoad, sizeof(itemsToLoad));

	for(size_t i = 0; i < itemsToLoad; i++)
	{
		char symbol;
		ifs.read((char*) &symbol, sizeof(symbol));
		addItem(symbol);
	}
}