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
		getline(inputDataFile, buffer);
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

void readGraphFromFile(string text, Graph &map)
{
	ifstream inputDataFile(text, ios::in);
	if (!inputDataFile.is_open())
	{
		cout << "File not found!" << endl;
		return;
	}

	int vertexNumber = 0;
	inputDataFile >> vertexNumber;
	
	int edgesNumber = 0;
	inputDataFile >> edgesNumber;
	
	vector<pair<int, int>> matrix;
	matrix.resize(edgesNumber);

	for (int i = 0; i < vertexNumber; ++i)
	{
		for (int j = 0; j < edgesNumber; ++j)
		{
			int number = 0;
			inputDataFile >> number;

			if (number == 1)
			{
				matrix[j].first = i;
			}
			else if (number == -1)
			{
				matrix[j].second = i;
			}
		}
	}
	

	for (const auto &i : matrix)
	{
		int from = i.first + 1;
		int to = i.second + 1;
		map.addEdge(from, to, true);
	}

	inputDataFile.close();
}