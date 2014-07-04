#pragma once

#include "Item.h" 

class Sword : public Item
{
public:
	Sword();
	virtual ~Sword() { };

	virtual const float getAttack() const;
	virtual const float getDefence() const;
	virtual const char getSymbol() const;
	virtual char* toString() const;
};
