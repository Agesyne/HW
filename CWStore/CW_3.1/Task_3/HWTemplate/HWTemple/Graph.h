#pragma once
#include <vector>
#include "GraphField.h"


class Graph
{
private:
	std::vector<GraphField> vertex;
public:
	Graph(const int size = 0);

	void addEdge(int from, int to, bool isDirected = false, const int weight = 0, bool isWeighted = false);

	GraphField &operator[] (const int vertexNumber);

	void dfs(const int currentVertex, std::vector<bool> &isReacheable);

	int getSize();
};
