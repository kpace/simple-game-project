#pragma once

#include "Item.h"

class Pendant : public Item
{
public:
	Pendant();
	virtual ~Pendant() { } ;

	virtual const float getAttack() const;
	virtual const float getDefence() const;
	virtual const char getSymbol() const;
	virtual char* toString() const;
};