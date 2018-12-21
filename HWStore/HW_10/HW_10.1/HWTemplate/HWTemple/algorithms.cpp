#include "pch.h"
#include "algorithms.h"
#include <iostream>
#include <vector>
#include "GraphField.h"
#include "Graph.h"
using namespace std;


void formCountries(const int capitalNumber, const int citiesNumber, vector<vector<GraphField *>> &countries, Graph &map)
{
	// Перебираем всё количество вершин
	for (int counter = 0; counter < citiesNumber - capitalNumber; ++counter)
	{
		bool isChosen = false;
		GraphField *addingVertex = nullptr;
		int addingVertexWeight = 0;

		// Проходим все города страны, ища новый город
		for (auto const &i : countries[counter % capitalNumber])
		{
			// Ищем самую короткую дорогу к ничейному городу
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
	}
}