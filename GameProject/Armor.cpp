#include "Armor.h"

Armor::Armor() : Item(0, 100, 'A') {}

const float Armor::getAttack() const
{
	return this->attack;
}

const float Armor::getDefence() const
{
	return this->defence;
}

const char Armor::getSymbol() const
{
	return this->symbol;
}
char* Armor::toString() const
{
	return "Armor";
}