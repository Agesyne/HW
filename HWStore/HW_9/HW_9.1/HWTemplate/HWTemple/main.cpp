#include "pch.h"
#include <iostream>
#include <string>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
#include "HashTable.h"
#include "readFile.h"
using namespace std;


int main()
{
	checkFromFile();

	vector<string> data;
	readFile("data.txt", data);

	HashTable table;
	for (const auto i : data)
	{
		table.add(i);
	}

	table.printAllData();

	return 0;
}