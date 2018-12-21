#include "pch.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


Graph::Graph(const int size)
{
	vertex.resize(size);
}

void Graph::addEdge(int from, int to, bool isDirected, const int weight, bool isWeighted)
{
	if (max(from, to) > vertex.size())
	{
		vertex.resize(max(from, to));
	}
	--to;
	--from;

	Edge newEdge(from, to, weight, isWeighted, isDirected);
	vertex[from].edges.push_back(newEdge);
	sort(vertex[from].edges.begin(), vertex[from].edges.end());
}

GraphField &Graph::operator[] (const int vertexNumber)
{
	return vertex[vertexNumber];
}

int Graph::getSize()
{
	return vertex.size();
}

void Graph::dfs(const int currentVertex, vector<bool> &isReacheable)
{
	if (isReacheable[currentVertex] == true)
	{
		return;
	}
	isReacheable[currentVertex] = true;

	for (const auto &i : vertex[currentVertex].edges)
	{
		dfs(i.to, isReacheable);
	}
}