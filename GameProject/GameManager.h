#pragma once

#include "Hero.h"
#include "Map.h"
#include "Orc.h"
#include "Undead.h"

///
/// GameManager - singleton class
///

class GameManager
{
	static const int REQUIRED_GOLD = 120; // required gold for win

	Hero* hero;
	Map* map;

	const char* saveFileName; // name of save/load file
public:

	static GameManager& getInstance(const char*, const char*);

	void start();

private:

	void menu();
	void heroMovement(const char);

	void printInfo() const;
	void battle(Monster*);
	bool processCell(const char);
	Monster* createMonster(const char);

	void changeLevel(const char);
	void saveGame(const char*) const;
	void loadGame(const char*);
private:

	GameManager(const char*, const char*);
	~GameManager();
	GameManager(const GameManager&); // not implemented
	GameManager& operator=(const GameManager&); // not implemented
};