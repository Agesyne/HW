#include "pch.h"
#include <iostream>
#include <string>
#include "algorithms.h"
#include "Graph.h"
#include "readFile.h"
using namespace std;


int main()
{
	//checkFromFile();

	Graph map;
	readGraphFromFile("data.txt", map);

	vector<vector<bool>> isReacheable;
	checkAllVertex(map, isReacheable);

	cout << "Vertex: ";
	for (int i = 0; i < map.getSize(); ++i)
	{
		if (isReacheableFromEverywhere(i, isReacheable))
		{
			cout << i + 1 << " ";
		}
	}
	cout << endl;

	return 0;
}