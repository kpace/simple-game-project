#pragma once

#include <Windows.h>

// Item - abstract class inherited by various monsters

class Monster
{
protected:
	const float life;
	const float attack;
	const float defence;
	const float gold;

	const char symbol;
public:
	Monster(float, float, float, float, const char);
	virtual ~Monster() { };

	virtual float getAttack() const = 0;
	virtual float getDefence() const = 0;
	virtual float getLife() const = 0;
	virtual float getGold() const = 0;
	virtual const char getSymbol() const = 0;
};