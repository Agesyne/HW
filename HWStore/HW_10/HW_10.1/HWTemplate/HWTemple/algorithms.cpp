#include "pch.h"
#include "algorithms.h"
#include <iostream>
#include <vector>
#include "GraphField.h"
#include "Graph.h"
using namespace std;


bool isAllAdded(Graph &map)
{
	for (int i = 0; i < map.getSize(); ++i)
	{
		if (!map[i].isGotCountry)
		{
			return false;
		}
	}

	return true;
}

void formCountries(const int capitalNumber, const int citiesNumber, vector<vector<GraphField *>> &countries, Graph &map)
{
	// ���������� �� ���������� ������
	int counter = 0;
	while (!isAllAdded(map))
	{
		bool isChosen = false;
		GraphField *addingVertex = nullptr;
		int addingVertexWeight = 0;

		// �������� ��� ������ ������, ��� ����� �����
		for (auto const &i : countries[counter % capitalNumber])
		{
			// ���� ����� �������� ������ � ��������� ������
			for (auto &j : i->edges)
			{
				if (!map[j.to].isGotCountry && (!isChosen || j.weight < addingVertexWeight))
				{
					isChosen = true;
					addingVertex = &map[j.to];
					addingVertexWeight = j.weight;
					break;
				}
			}

		}

		if (addingVertex != nullptr)
		{
			addingVertex->isGotCountry = true;
			countries[counter % capitalNumber].push_back(addingVertex);
		}

		counter++;
	}
}