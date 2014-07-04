#include "Orc.h"

Orc::Orc() : Monster(30, 30, 30, 40, 'O')
{ }

float Orc::getAttack() const
{
	return this->attack;
}

float Orc::getDefence() const
{
	return this->defence;
}

float Orc::getLife() const
{
	return this->life;
}

float Orc::getGold() const
{
	return this->gold;
}

const char Orc::getSymbol() const
{
	return this->symbol;
}