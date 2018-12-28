#include "pch.h"
#include "algorithms.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "Graph.h"
using namespace std;

bool isAllVertexAdded(vector<bool> &isAdded)
{
	for (int i = 0; i < isAdded.size(); ++i)
	{
		if (!isAdded[i])
		{
			return false;
		}
	}

	return true;
}


const Edge *findMinEdge(Graph &map, vector<bool> &isAdded)
{
	Edge *addingEdge = nullptr;
	bool isFirst = true;

	for (int i = 0; i < isAdded.size(); ++i)
	{
		if (!isAdded[i])
		{
			continue;
		}

		for (auto &i : map[i].edges)
		{
			if (!isAdded[i.to] && (isFirst || i.weight < addingEdge->weight))
			{
				addingEdge = &i;
				isFirst = false;
				break;
			}
		}
	}

	return addingEdge;
}

Graph *makeDyingTree(Graph &map, int vertexNumber)
{
	auto dyingTree = new Graph(map.getSize());
	vector<bool> isAdded(map.getSize());
	isAdded[vertexNumber] = true;

	while (!isAllVertexAdded(isAdded))
	{
		auto addingEdge = findMinEdge(map, isAdded);

		if (addingEdge == nullptr)
		{
			break;
		}
		else
		{
			dyingTree->addEdge(addingEdge->from + 1, addingEdge->to + 1, addingEdge->isDirected, addingEdge->weight, addingEdge->isWeighted);
			isAdded[addingEdge->to] = true;
		}
	}

	return dyingTree;
}

void printAllEdges(Graph &map, const string &text)
{
	if (text != "")
	{
		ofstream outputFileStream(text, ios::trunc);
		outputFileStream.close();
	}

	for (int i = 0; i < map.getSize(); ++i)
	{
		for (const auto &j : map[i].edges)
		{
			if (text != "")
			{
				ofstream outputFileStream(text, ios::app);
				outputFileStream << "(" << j.from + 1 << ":" << j.to + 1 << ") = " << j.weight << endl;
				outputFileStream.close();
			}
			else
			{
				cout << "(" << j.from + 1 << ":" << j.to + 1 << ") = " << j.weight << endl;
			}
		}
	}
}