#include "pch.h"
#include <iostream>
#include <string>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
#include "Graph.h"
#include "readFile.h"
#
using namespace std;


int main()
{
	checkFromFile();
	int citiesNumber = 0;
	int capitalsNumber = 0;
	Graph map(citiesNumber);
	vector<vector<GraphField *>> countries;

	readGraphFromFile("data.txt", map, countries, citiesNumber, capitalsNumber);
	formCountries(capitalsNumber, citiesNumber, countries, map);

	for (int i = 0; i < capitalsNumber; ++i)
	{
		cout << "Country #" << i + 1 << ": ";
		for (auto const &j : countries[i])
		{
			cout << j->edges[0].from + 1<< " ";
		}
		cout << endl;
	}

	return 0;
}