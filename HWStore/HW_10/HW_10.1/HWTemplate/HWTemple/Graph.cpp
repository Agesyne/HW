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

//void Graph::addEdge(int from, int to)
//{
//	if (max(from, to) > vertex.size())
//	{
//		vertex.resize(max(from, to));
//	}
//	--to;
//	--from;
//
//	for (auto const &i : vertex[from])
//	{
//		if (i.to == to)
//		{
//			return;
//		}
//	}
//	GraphField newGraphField1(to);
//	vertex[from].push_back(newGraphField1);
//
//
//	for (auto const &i : vertex[to])
//	{
//		if (i.to == to)
//		{
//			return;
//		}
//	}
//	GraphField newGraphField2(from);
//	vertex[to].push_back(newGraphField2);
//}

GraphField &Graph::operator[] (const int vertexNumber)
{
	return vertex[vertexNumber];
}

int Graph::getSize()
{
	return vertex.size();
}