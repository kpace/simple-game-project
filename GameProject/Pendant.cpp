#include "Pendant.h"

Pendant::Pendant () : Item(100, 100, 'P') { }

const float Pendant::getAttack() const
{
	return this->attack;
}

const float Pendant::getDefence() const
{
	return this->defence;
}

const char Pendant::getSymbol() const
{
	return this->symbol;
}
char* Pendant::toString() const
{
	return "Pendant";
}
