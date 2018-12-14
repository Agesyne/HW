#include "pch.h"
#include "algorithms.h"
#include <iostream>
#include <vector>
using namespace std;

void makeRows(vector<vector<int> > &data, vector<pair<int,int> > &rows, const int n, const int m)
{
	for (int i = 0; i < n; ++i)
	{
		int minIndex = 0;
		for (int j = 0; j < m; ++j)
		{
			if (data[i][j] < data[i][minIndex])
			{
				minIndex = j;
			}
		}
		rows[i] = make_pair(data[i][minIndex], minIndex);
	}
}

void makeCells(vector<vector<int> > &data, vector<pair<int, int> > &cells, const int n, const int m)
{
	for (int j = 0; j < m; ++j)
	{
		int maxIndex = 0;
		for (int i = 0; i < n; ++i)
		{
			if (data[i][j] > data[maxIndex][j])
			{
				maxIndex = i;
			}
		}
		cells[j] = make_pair(data[maxIndex][j], maxIndex);
	}
}
