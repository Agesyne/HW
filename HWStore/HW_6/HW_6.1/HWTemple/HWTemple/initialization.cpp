#include "pch.h"
#include <iostream>
#include "initialization.h"
#include <string>
#include <array>
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