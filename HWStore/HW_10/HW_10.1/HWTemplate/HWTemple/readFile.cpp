#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "readFile.h"
#include "Graph.h"
#include "GraphField.h"
using namespace std;

void readFile(string text, vector<string> &data)
{
	ifstream inputDataFile(text, ios::in);
	if (!inputDataFile.is_open())
	{
		cout << "File not found!" << endl;
		return;
	}

	while (!inputDataFile.eof()) {
		string buffer;
		inputDataFile >> buffer;
		if (buffer == "")
		{
			continue;
		}
		data.push_back(buffer);
	}

	inputDataFile.close();
}

void readResultFile(string text, vector<vector<int>> &data, const int linesNumber)
{
	ifstream inputDataFile(text, ios::in);
	if (!inputDataFile.is_open())
	{
		cout << "File not found!" << endl;
		return;
	}

	data.resize(linesNumber);

	for (int linesCounter = 0; linesCounter < linesNumber; ++linesCounter)
	{
		string inputString;
		getline(inputDataFile, inputString);

		stringstream str;
		str << inputString;

		int numbersCounter = 0;
		str >> numbersCounter;

		for (int i = 0; i < numbersCounter; ++i)
		{
			int number = 0;
			str >> number;
			--number;

			data[linesCounter].push_back(number);
		}
	}

	inputDataFile.close();
}

void readGraphFromFile(string text, Graph &map, vector<vector<GraphField *>> &countries, int &citiesNumber, int &capitalsNumber)
{
	ifstream inputDataFile(text, ios::in);
	if (!inputDataFile.is_open())
	{
		cout << "File not found!" << endl;
		return;
	}
	int edgesNumber = 0;

	inputDataFile >> citiesNumber;
	inputDataFile >> edgesNumber;

	for (int i = 0; i < edgesNumber; ++i)
	{
		int from = 0;
		inputDataFile >> from;
		
		int to = 0;
		inputDataFile >> to;
		
		int weight = 0;
		inputDataFile >> weight;

		map.addEdge(from, to, false, weight, true);
		map.addEdge(to, from, false, weight, true);
	}

	inputDataFile >> capitalsNumber;
	countries.resize(capitalsNumber);
	for (int i = 0; i < capitalsNumber; ++i)
	{
		int capital = 0;
		inputDataFile >> capital;
		--capital;
		map[capital].isGotCountry = true;
		countries[i].push_back(&map[capital]);
	}

	inputDataFile.close();
}