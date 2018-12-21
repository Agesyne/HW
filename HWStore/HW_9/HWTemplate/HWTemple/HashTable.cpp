#include "pch.h"
#include "HashTable.h"
#include "HashFunction.h"
#include <list>
#include <vector>
using namespace std;



HashTable::HashTable(size_t initSize)
{
	map.resize(initSize);
}

bool HashTable::find(string sourse)
{
	const int keyNumber = hashFunction(sourse) % map.size();

	for (auto const &i : map[keyNumber])
	{
		if (i.first == sourse)
		{
			return true;
		}
	}

	return false;
}

void HashTable::add(string sourse)
{
	const int key = hashFunction(sourse) % map.size();

	for (auto &i : map[key])
	{
		if (i.first == sourse)
		{
			i.second++;
			return;
		}
	}
	map[key].push_back(make_pair(sourse, 1));
	mbResize();
}

void HashTable::erase(string sourse)
{
	const int key = hashFunction(sourse) % map.size();

	for (auto i = map[key].begin(); i != map[key].end(); ++i)
	{
		if ((*i).first == sourse)
		{
			map[key].erase(i);
			break;
		}
	}
}

void HashTable::printAllData()
{
	int elementsCounter = 0;
	int maxNumberElementInList = 0;
	int listCounter = 0;
	for (const auto &i : map)
	{
		if (i.size() != 0)
		{
			++listCounter;
		}
		int localElementCounter = 0;
		for (const auto &j : i)
		{
			cout << "(" << j.first << ":" << j.second << ")" << endl;
			++localElementCounter;
		}

		if (maxNumberElementInList < localElementCounter)
		{
			maxNumberElementInList = localElementCounter;
		}
		elementsCounter += localElementCounter;
	}

	cout << "Solidity (%): " << (double)listCounter / map.size() * 100 << endl;
	cout << "Max length of list: " << maxNumberElementInList << endl;
	cout << "Average length of lists: " << (double)elementsCounter / map.size() << endl;
}

void HashTable::mbResize()
{
	int elementsCounter = 0;
	for (const auto &i : map)
	{
		for (const auto &j : i)
		{
			++elementsCounter;
		}
	}

	if ((double)elementsCounter / map.size() > 1.5)
	{
		const int newSize = map.size() * 2;
		HashTable newHashTable(newSize);
		for (auto const &i : map)
		{
			for (auto const &j : i)
			{
				newHashTable.add(j.first);
			}
		}

		map.clear();
		map.resize(newSize);

		for (auto const &i : newHashTable.map)
		{
			for (auto const &j : i)
			{
				add(j.first);
			}
		}
	}
}
