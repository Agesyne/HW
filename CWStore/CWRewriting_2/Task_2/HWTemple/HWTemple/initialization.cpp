#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int initNumber(string text)
{
	int number = 0;
	cout << text;
	cin >> number;
	return number;
}

void initArray(string text, int initingArray[], int arraySize)
{
	cout << text;
	for (int i = 0; i < arraySize; i++)
	{
		int number = 0;
		cin >> number;
		initingArray[i] = number;
	}
}