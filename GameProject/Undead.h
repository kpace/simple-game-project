#pragma once

#include <iostream>

#include "Monster.h"

class Undead : public Monster
{
public:
	Undead();
	virtual ~Undead() { };

	virtual float getAttack() const;
	virtual float getDefence() const;
	virtual float getLife() const;
	virtual float getGold() const;
	virtual const char getSymbol() const;
};