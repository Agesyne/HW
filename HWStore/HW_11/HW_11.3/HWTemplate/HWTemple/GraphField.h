#pragma once
#include <vector>


struct Edge
{
	int from;
	int to;
	int weight;
	bool isWeighted;
	bool isDirected;

	Edge(int inFrom, int inTo, int inWeight = 0, bool inIsWeighted = false, bool inIsDirected = false)
	{
		from = inFrom;
		to = inTo;
		weight = inWeight;
		isWeighted = inIsWeighted;
		isDirected = inIsDirected;
	}

	bool operator <(Edge second)
	{
		return weight < second.weight;
	}
};

struct GraphField
{
	bool isAdded;
	std::vector<Edge> edges;
};