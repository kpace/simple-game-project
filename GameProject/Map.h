//map.h
#pragma once

#include <iostream>
#include <fstream>

class Map 
{
private:

	char** ppArr;
	size_t height;
	size_t width;

public:

	Map();
	Map(const char*);
	~Map();

	void printMap() const;

	char getCell(int, int) const;
	void setCell(int, int, char);
	size_t getHeight() const;
	size_t getWidth() const;

	void loadMapTextFile(const char*);

	void save(std::ofstream&) const;
	void load(std::ifstream&);
private:

	void allocateMemory();
	void freeArr(size_t);
private:

	Map(const Map &); // not implemented
	Map& operator=(const Map&); // not implemented
};
