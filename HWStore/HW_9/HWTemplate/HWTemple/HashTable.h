#pragma once
#include <list>
#include <vector>

#define INIT_SIZE 16

class HashTable
{
private:
	std::vector<std::list<std::pair<std::string, int>>> map;
public:

	HashTable(size_t initSize = INIT_SIZE);

	void mbResize();

	bool find(const std::string sourse);

	void add(const std::string sourse);

	void erase(const std::string sourse);

	void printAllData();
};

