#pragma once

#include "Item.h"

class Armor : public Item
{
public:
	Armor();
	virtual ~Armor() { };

	virtual const float getAttack() const;
	virtual const float getDefence() const;
	virtual const char getSymbol() const;
	virtual char* toString() const;
};