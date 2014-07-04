#include "Item.h"

Item::Item(const float att, const float def, const char sym) 
	: attack(att), defence(def), symbol(sym)
{
	this->isEquiped = false;
}
