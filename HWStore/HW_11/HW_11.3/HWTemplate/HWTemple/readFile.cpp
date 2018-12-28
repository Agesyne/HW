#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "readFile.h"
#include "Graph.h"
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

void readFileByLines(string text, vector<string> &data)
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

	for (int i = 0; i < vertexNumber; ++i)
	{
		for (int j = 0; j < vertexNumber; ++j)
		{
			int weight = 0;
			inputDataFile >> weight;

			if (weight == 0)
			{
				continue;
			}

			map.addEdge(i + 1, j + 1, false, weight, true);
		}
	}

	inputDataFile.close();
}