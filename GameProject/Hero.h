//Hero.cpp

#pragma once

#include "Position.h"
#include "Map.h"
#include "Inventory.h"
#include "HelpFunctions.h"

class Hero
{
	const char symbol;

	float life;
	float attack;
	float defence;
	float gold;

	Inventory* inventory;
	Position position;
public:
	Hero(const Map&);
	~Hero();
	char getSymbol() const;
	float getLife() const;
	float getAttack() const;
	float getDefence() const;
	float getGold() const;
	Position getPosition() const;

	void setLife(const float);
	void setAttack(const float);
	void setDefence(const float);
	void setGold(const float);
	void setI(const int);
	void setJ(const int);
	void setHeroPosition(const int, const int);

	void findHeroPosition(const Map&);

	void printHeroState() const;
	void addItemInInventory(const char);
	void putOnItem();
public:

	void moveUp(Map&);
	void moveDown(Map&);
	void moveLeft(Map&);
	void moveRight(Map&);

	void processChar(const char);

	void save(std::ofstream&) const;
	void load(std::ifstream&);
private:
	Hero(const Hero&); // not implemented
	Hero& operator=(const Hero&); // not implemented
};