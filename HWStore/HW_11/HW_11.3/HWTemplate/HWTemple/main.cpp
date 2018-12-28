#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "check.h"
#include "Graph.h"
#include "initialization.h"
#include "algorithms.h"
#include "readFile.h"
using namespace std;


int main()
{
	checkFromFile();
	Graph map;
	readGraphFromFile("data.txt", map);

	auto dyingTree = makeDyingTree(map, 0);

	printAllEdges(*dyingTree);

	delete dyingTree;
	return 0;
}