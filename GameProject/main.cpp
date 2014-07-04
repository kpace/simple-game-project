//main.cpp

#include <iostream>

#include "GameManager.h"
#include "HelpFunctions.h"

int main()
{

	GameManager* pGame = &GameManager::getInstance("level1.txt", "saveGame.dat");
	pGame->start();


	return 0;
}