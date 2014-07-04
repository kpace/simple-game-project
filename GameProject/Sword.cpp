#include "Sword.h"

Sword::Sword() : Item(100, 0, 'S') { }

const float Sword::getAttack() const
{
	return this->attack;
}

const float Sword::getDefence() const
{
	return this->defence;
}

const char Sword::getSymbol() const
{
	return this->symbol;
}

char* Sword::toString() const
{
	return "Sword";
}
