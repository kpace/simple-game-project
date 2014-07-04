#pragma once

#include <fstream>

// Item - abstract class inherited by various items

class Item
{
public:
	bool isEquiped;
protected:
	const float attack;
	const float defence;
	const char symbol;
public:
	Item(const float, const float, const char);
	virtual ~Item() { };

	virtual const float getAttack() const = 0; 
	virtual const float getDefence() const = 0;
	virtual const char getSymbol() const = 0;
	virtual char* toString() const = 0;
};