#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
using namespace std;


int main()
{
	//checkFromFile();
	
	vector<vector<int > > data;
	int n = 0;
	int m = 0;
	enterData(&n, &m, data);

	vector<pair<int, int> > cells, rows;
	cells.resize(m);
	rows.resize(n);

	makeRows(data, rows, n, m);

	makeCells(data, cells, n, m);

	int counter = 0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (data[i][j] == rows[i].first && data[i][j] == cells[j].first)
			{
				cout << "(" << i << "," << j << ") = (" << data[i][j] << ") is the point" << endl;
				counter++;
			}
		}
	}

	if (counter == 0)
	{
		cout << "No points" << endl;
	}

	return 0;
}