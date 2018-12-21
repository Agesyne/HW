#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "algorithms.h"
#include "readFile.h"
#include "check.h"
using namespace std;

void autoGeneratedCheck()
{
	srand(0);
	const int debugNumber = 10;

	for (int i = 0; i < debugNumber; i++)
	{
		if (0)
		{
			exit(1);
		}
	}
}

bool checkIfResultRight(vector<vector<GraphField *>> &countries, vector<vector<int>> &answer)
{
	for (int i = 0; i < countries.size(); ++i)
	{
		if (countries[i].size() != answer[i].size())
		{
			return false;
		}

		for (int j = 0; j < countries[i].size(); ++j)
		{
			if (countries[i][j]->edges[0].from != answer[i][j])
			{
				return false;
			}
		}
	}

	return true;
}

void checkFromFile()
{
	vector<string> data;
	readFile("checkData.txt", data);

	vector<string> results;
	readFile("resultData.txt", results);

	auto iData = data.begin();
	auto iResults = results.begin();
	while (iData != data.end() && iResults != results.end())
	{
		int citiesNumber = 0;
		int capitalsNumber = 0;
		Graph map(citiesNumber);
		vector<vector<GraphField *>> countries;

		readGraphFromFile(*iData, map, countries, citiesNumber, capitalsNumber);
		formCountries(capitalsNumber, citiesNumber, countries, map);

		vector<vector<int>> answer;
		readResultFile(*iResults, answer, capitalsNumber);

		if (!checkIfResultRight(countries, answer))
		{
			cout << "Mistakes";
			exit(1);
		}
		++iData;
		++iResults;
	}
}