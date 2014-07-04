//map.cpp

#pragma once

#include "Map.h"

Map::Map()
{
	ppArr = NULL;
	this->height = 0;
	this->width = 0;
}

// @param level - name of text file

Map::Map(const char* level)
{
	ppArr = NULL;
	this->loadMapTextFile(level);
}

Map::~Map()
{
	if(ppArr != NULL)
		this->freeArr(getHeight());
}

// Loads map from text file

void Map::loadMapTextFile(const char* level)
{
	if(ppArr != NULL)
		this->freeArr(getHeight());

	std::ifstream in(level);

	if(in)
	{
		in >> height;
		in >> width;

		allocateMemory();

		in.get();

		for(size_t i = 0; i < height; i++)
		{
			in.getline(ppArr[i], width+1);
		}

		in.close();

	}
	else
		std::cerr << "\nProblem with opening file. Next level is not loaded!\n";
}

// Allocates memory for ppArr
// @throws - bad_alloc

void Map::allocateMemory()
{
	ppArr = NULL;
	size_t i;
	try
	{
		ppArr = new char * [height];

		for(i = 0; i < height; i++)
		{
			ppArr[i] = new char[width + 1];
		}
	}
	catch(std::bad_alloc&)
	{
		freeArr(i);

		throw;
	}
}

// Frees memory from ppArr by given index

void Map::freeArr(size_t height)
{
	if(ppArr != NULL)
	{
		for(size_t i = 0; i < height; i++)
		{
			delete [] ppArr[i];
		}

		delete [] ppArr;
	}

	this->height = 0;
	this->width = 0;
}

// Prints map in console

void Map::printMap() const
{
	for(size_t i = 0; i < height; i++)
		std::cout << ppArr[i] << std::endl;
}

// Saves the map in binary file

void Map::save(std::ofstream& ofs) const
{
	ofs.write((char*) &height, sizeof(height));
	ofs.write((char*) &width, sizeof(width));

	for(size_t i = 0; i < height; i++)
		for(size_t j = 0; j < width+1; j++)
			ofs.write((char*) &ppArr[i][j], sizeof(ppArr[i][j]));
}

// Loads the map from binary file

void Map::load(std::ifstream& ifs)
{
	freeArr(getHeight());

	ifs.read((char*) &height, sizeof(height));
	ifs.read((char*) &width, sizeof(width));

	allocateMemory();

	for(size_t i = 0; i < height; i++)
		for(size_t j = 0; j < width+1; j++)
			ifs.read((char*) &ppArr[i][j], sizeof(ppArr[i][j]));
}

size_t Map::getHeight() const
{ 
	return this->height; 
}

size_t Map::getWidth() const
{ 
	return this->width; 
}

char Map::getCell(int i, int j) const
{
	return ppArr[i][j];
}

void Map::setCell(int i, int j, char sign)
{
	this->ppArr[i][j] = sign;
}
