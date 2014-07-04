#pragma once

#include "Monster.h"
#include <iostream>

class Orc : public Monster
{
public:
	Orc();
	virtual ~Orc() { };

	virtual float getAttack() const;
	virtual float getDefence() const;
	virtual float getLife() const;
	virtual float getGold() const;
	virtual const char getSymbol() const;
};