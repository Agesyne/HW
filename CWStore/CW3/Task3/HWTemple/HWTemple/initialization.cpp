#include "pch.h"
#include <iostream>
#include <string>
#include <array>
#include <vector>
using namespace std;


int initNumber(string text)
{
	int number = 0;
	cout << text;
	cin >> number;
	return number;
}

template<std::size_t SIZE>
void initArray(string text, array<int, SIZE>& initingArray)
{
	cout << text;
	for (const int &i : initingArray)
	{
		int number = 0;
		cin >> number;
		i = number;
	}
}

void enterData(int *n, int *m, vector<vector<int> > &data)
{
	cout << "Enter n*m: ";
	cin >> *n >> *m;
	cout << "Enter array:";
	data.resize(*n);
	for (int i = 0; i < *n; ++i)
	{
		data[i].resize(*m);
		for (int j = 0; j < *m; ++j)
		{
			cin >> data[i][j];
		}
	}
}