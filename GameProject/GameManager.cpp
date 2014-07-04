#pragma once

#include "GameManager.h"

// @param level - name ot .txt file
// @param saveFile - name of binary file

GameManager& GameManager::getInstance(const char* level, const char* saveFile)
{
	static GameManager instance(level, saveFile);
	return instance;
}

// @param level - name ot .txt file
// @param saveFile - name of binary file

GameManager::GameManager(const char* level, const char* saveFile)
{
	saveFileName = saveFile;

	try
	{
		this->map = new Map(level);
		this->hero = new Hero(*map);
	}
	catch(std::bad_alloc& e)
	{
		system("cls");
		std::cout << "Problem with memory. Restart the app.\n";
		std::cout << "\"" << e.what() << "\"";
	}
}

GameManager::~GameManager()
{
	delete map;
	delete hero;
}

// Starts the game

void GameManager::start()
{
	char input;

	while(true)
	{ 
		system("cls");
		std::cin.sync();

		printInfo();

		std::cin.get(input);

		//toLowerCase(input);

		char currentCell = '\0';
		std::cout << input;

		if(input == 'M' || input == 'm')
			this->menu();

		if(input == 'w' || input == 'a' || input == 's' || input == 'd')
			this->heroMovement(input);
	}
}

// Represents menu for the user

void GameManager::menu()
{
	system("cls");
	std::cout << "Select: \n"
		<< "1. Inventory\n"
		<< "2. Save Game\n"
		<< "3. Load Game\n"
		<< "4. Quit\n"
		<< "5. Back\n";

	char input;
	std::cin >> input;

	switch(input)
	{
	case '1' : 
		{
			hero->putOnItem();
			break;
		}
	case '2' : 
		{
			saveGame(saveFileName);
			break;
		}
	case '3' : 
		{
			loadGame(saveFileName);
			break;
		}
	case '4' : 
		{
			exit(0);
			break;
		}
	default :
		{
			std::cout << "\nBad input!\n";
			system("PAUSE");
		}
	}
}

// Moves the hero on the map
// by given direction

void GameManager::heroMovement(const char direction)
{
	Position currentPos = hero->getPosition();
	int i = currentPos.i;
	int j = currentPos.j;

	char currentCell = '\0';

	switch(direction)
	{

	case 'w' : 
		{
			if(map->getCell(i-1, j) != '#')
			{
				currentCell = map->getCell(i-1, j);

				if(processCell(currentCell))
					hero->moveUp(*map);
			}
			break;
		}
	case 's' : 
		{
			if(map->getCell(i+1, j) != '#')
			{
				currentCell = map->getCell(i+1, j);

				if(processCell(currentCell))
					hero->moveDown(*map);
			}
			break;
		}
	case 'a' :
		{
			if(map->getCell(i, j-1) != '#')
			{
				currentCell = map->getCell(i, j-1);

				if(processCell(currentCell))
					hero->moveLeft(*map);
			}
			break;
		}
	case 'd' : 
		{
			if(map->getCell(i, j+1) != '#')
			{
				currentCell = map->getCell(i, j+1);

				if(processCell(currentCell))
					hero->moveRight(*map);
			}
			break;
		}
	}
}

// Prints state of game 
// and instructions for the user

void GameManager::printInfo() const
{
	map->printMap();
	hero->printHeroState();

	std::cout << "Controls:\n";
	std::cout << "Move - w, a, s, d\n";
	std::cout << "Menu - m\n";
}

// Calculates the outcome from battle
// between hero and given monster

void GameManager::battle(Monster* m)
{
	float monsterOverall = m->getAttack() + m->getDefence() + m->getLife();
	float heroOverall = hero->getAttack() + hero->getDefence() + hero->getLife();

	float newLife = hero->getLife() -  (monsterOverall / heroOverall) * 50;
	float newGold = hero->getGold() + m->getGold();

	if(newLife <= 0)
	{
		std::cout << "\nYOU ARE DEAD!!!";
		std::cout << "\nYOU ARE DEAD!!!";
		std::cout << "\nYOU ARE DEAD!!!\n";
		exit(0);
	}

	else
	{
		hero->setLife(newLife);
		hero->setGold(newGold);
	}
	delete m;
}

// Process the char of the current position of Hero
// \return - true if the hero have to be moved
//         - false if the hero don't have to be moved

bool GameManager::processCell(const char currentCell)
{
	if(currentCell == 'A' || currentCell == 'S' || currentCell == 'P')
	{
		hero->addItemInInventory(currentCell);
		return true;
	}

	if(currentCell == '1' || currentCell == '2' || currentCell == '3')
	{
		changeLevel(currentCell);
		return false;
	}

	if(currentCell == 'O' || currentCell == 'U')
	{
		Monster* monster = NULL;
		try
		{
			monster = createMonster(currentCell);
			battle(monster);
			return true;
		}
		catch(std::bad_alloc&)
		{
			std::cout << "\nMemory problem. The monster is not created\n";
			return false;
		}
	}

	if(currentCell == 'F')
	{
		if(hero->getGold() >= REQUIRED_GOLD)
		{
			system("cls");

			std::cout << '\a';
			std::cout << "CONGRATS !!! YOU WON !!!\n";

			exit(0);
		}
		else 
		{
			std::cout << "\nYou need " 
				<< REQUIRED_GOLD 
				<< " gold to finish the game.\n";

			system("PAUSE");
			return false;
		}
	}

	return true;
}

// Creates various monsters

Monster* GameManager::createMonster(const char cell)
{
	if(cell == 'O')
		return new Orc();
	if(cell == 'U')
		return new Undead();

}

// Loads next level from text file

void GameManager::changeLevel(const char level)
{
	switch(level)
	{
	case '1' :
		{
			map->loadMapTextFile("level1.txt");
			hero->findHeroPosition(*map);
			break;
		}
	case'2' :
		{
			map->loadMapTextFile("level2.txt");
			hero->findHeroPosition(*map);
			break;
		}
	case'3' :
		{
			map->loadMapTextFile("level3.txt");
			hero->findHeroPosition(*map);
			break;
		}
	}
}

// Saves the game in binary file 

void GameManager::saveGame(const char* file) const
{
	std::ofstream ofs;
	ofs.open(file, std::ios::binary | std::ios::out | std::ios::trunc);
	if(ofs)
	{
		hero->save(ofs);
		map->save(ofs);

		ofs.close();
	}
	else
	{
		std::cout << "\nCan't open file. ";
		std::cout << "The game is not saved.";
	}
}

// Loads game from binary file 

void GameManager::loadGame(const char* file)
{
	std::ifstream ifs;
	ifs.open(file, std::ios::binary | std::ios::in);
	if(ifs)
	{
		hero->load(ifs);
		map->load(ifs);

		ifs.close();
	}
	else
	{
		std::cout << "\nCan't open file. ";
		std::cout << "The game is not loaded.";
	}
}
