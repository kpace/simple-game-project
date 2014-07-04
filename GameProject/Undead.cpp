#include "Undead.h"

Undead::Undead() : Monster(15, 20, 15, 20, 'U')
{ }

float Undead::getAttack() const
{
	return this->attack;
}

float Undead::getDefence() const
{
	return this->defence;
}

float Undead::getLife() const
{
	return this->life;
}

float Undead::getGold() const
{
	return this->gold;
}

const char Undead::getSymbol() const
{
	return this->symbol;
}