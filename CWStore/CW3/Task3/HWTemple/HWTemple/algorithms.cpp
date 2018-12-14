#include "pch.h"
#include "algorithms.h"
#include <iostream>
#include <vector>
using namespace std;


void dfs(const int number, vector<int> &nodes, vector<vector<int> > &table)
{
	if (nodes[number] == 0)
	{
		return;
	}
	nodes[number] = 1;

	for (int i = 0; i < table[number].size(); ++i)
	{
		if (table[number][i] != 0)
		{
			dfs(i, nodes, table);
		}
	}
}