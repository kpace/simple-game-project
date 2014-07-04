//hero.cpp

#pragma once

//#include <Windows.h>

#include "Hero.h"


Hero::Hero(const Map& map) : symbol('H')
{	
	this->findHeroPosition(map);

	this->life = 100;
	this->attack = 100;
	this->defence = 100;
	this->gold = 0;
	this->inventory = new Inventory();
}

Hero::~Hero()
{
	delete this->inventory;
}

char Hero::getSymbol() const
{
	return this->symbol;
}

Position Hero::getPosition() const
{
	return this->position;
}

float Hero::getLife() const
{
	return this->life;
}

float Hero::getAttack() const
{
	return this->attack;
}

float Hero::getDefence() const
{
	return this->defence;
}

float Hero::getGold() const
{
	return this->gold;
}

void Hero::setLife(const float life)
{
	this->life = life;
}

void Hero::setAttack(const float attack)
{
	this->attack = attack;
}

void Hero::setDefence(const float defence)
{
	this->defence = defence;
}

void Hero::setGold(const float gold)
{
	this->gold = gold;
}

void Hero::setI(const int i)
{
	this->position.i = i;
}

void Hero::setJ(const int j)
{
	this->position.j = j;
}

// Sets the position of hero

void Hero::setHeroPosition(const int i, const int j)
{
	this->setI(i);
	this->setJ(j);
}

// Finds hero position on the map

void Hero::findHeroPosition(const Map& map)
{
	for(size_t i = 0; i < map.getHeight(); i++)
	{
		for(size_t j = 0; j < map.getWidth(); j++)
		{
			if(map.getCell(i, j) == symbol)
			{
				setHeroPosition(i,j);
			}
		}
	}
}

// Prints the features of the hero

void Hero::printHeroState() const
{
	std::cout << "\nLife: " << this->getLife();
	std::cout << "\nAttack: " << this->getAttack();
	std::cout << "\nDefence: " << this->getDefence();
	std::cout << "\nGold: " << this->getGold();
	inventory->printInventory();

	std::cout << std::endl;
}


// Equips hero with item from the inventory

void Hero::putOnItem()
{
	std::cout << "Which item do you want to put on?\n";
	std::cout << "Select:\n";

	for(size_t i = 0; i < inventory->getItemsCount(); i++)
	{
		Item* item = inventory->getItemAtPos(i);
		std::cout << "Press \'" << i + 1 << "\' for "
			<< item->toString() << std::endl;
	}

	char input;
	std::cin >> input;

	size_t index = fromCharToInt(input) - 1;

	if(index >= 0 &&  index < inventory->getItemsCount())
	{
		Item* item = inventory->getItemAtPos(index);

		if(item->isEquiped == false)
		{
			setAttack(getAttack() + item->getAttack());
			setDefence(getDefence() + item->getDefence());

			item->isEquiped = true;
			std::cout << std::endl << item->toString();
			std::cout << " is succesfully equipped.\n\n";
			system("PAUSE");
		}
		else
		{
			std::cout << std::endl << item->toString();
			std::cout << " is already equipped.\n\n";
			system("PAUSE");
		}
	}
	else
	{
		std::cout << "\nBad input!\n\n";
		system("PAUSE");
	}
}

// Moves hero UP on the map

void Hero::moveUp(Map& map)
{
	Position currentPos = this->getPosition();
	int i = currentPos.i;
	int j = currentPos.j;


	map.setCell(i-1, j, this->getSymbol());
	map.setCell(i, j, ' ');
	setHeroPosition(i-1, j);
}

// Moves hero DOWN on the map

void Hero::moveDown(Map& map)
{
	Position currentPos = this->getPosition();
	int i = currentPos.i;
	int j = currentPos.j;


	map.setCell(i+1, j, this->getSymbol());
	map.setCell(i, j, ' ');
	setHeroPosition(i+1, j);

}

// Moves hero LEFT on the map

void Hero::moveLeft(Map& map)
{
	Position currentPos = this->getPosition();
	int i = currentPos.i;
	int j = currentPos.j;


	map.setCell(i, j-1, this->getSymbol());
	map.setCell(i, j, ' ');
	setHeroPosition(i, j-1);
}

// Moves hero RIGHT on the map

void Hero::moveRight(Map& map)
{
	Position currentPos = this->getPosition();
	int i = currentPos.i;
	int j = currentPos.j;

	map.setCell(i, j+1, this->getSymbol());
	map.setCell(i, j, ' ');
	setHeroPosition(i, j+1);
}

// Adds item in inventory

void Hero::addItemInInventory(const char c)
{
	inventory->addItem(c);
}

// Saves the features of hero in binary file

void Hero::save(std::ofstream& ofs) const
{
	ofs.write((char*) &life, sizeof(life));
	ofs.write((char*) &attack, sizeof(attack));
	ofs.write((char*) &defence, sizeof(defence));
	ofs.write((char*) &gold, sizeof(gold));
	ofs.write((char*) &position, sizeof(position));
	inventory->save(ofs);

}

// Loads the features of hero from binary file

void Hero::load(std::ifstream& ifs)
{
	ifs.read((char*) &life, sizeof(life));
	ifs.read((char*) &attack, sizeof(attack));
	ifs.read((char*) &defence, sizeof(defence));
	ifs.read((char*) &gold, sizeof(gold));
	ifs.read((char*) &position, sizeof(position));

	inventory->load(ifs);
}