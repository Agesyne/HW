#include "pch.h"
#include "algorithms.h"
#include "Graph.h"
using namespace std;


void checkAllVertex(Graph &map, vector<vector<bool>> &isReacheable)
{
	isReacheable.resize(map.getSize());
	for (int i = 0; i < map.getSize(); ++i)
	{
		isReacheable[i].resize(map.getSize());
		map.dfs(i, isReacheable[i]);
	}
}

bool isReacheableFromEverywhere(const int vertexNumber, const vector<vector<bool>> &isReacheable)
{
	for (const auto &i : isReacheable[vertexNumber])
	{
		if (i == false)
		{
			return false;
		}
	}

	return true;
}