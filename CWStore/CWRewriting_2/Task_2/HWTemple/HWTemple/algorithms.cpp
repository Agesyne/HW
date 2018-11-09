#include "pch.h"
#include "algorithms.h"
#include <iostream>
#include <string>
using namespace std;


void printArray(string text, const int printingArray[], const int low, const int high)
{
	cout << text;
	for (int i = low; i <= high; i++)
	{
		cout << printingArray[i] << ' ';
	}
	cout << endl;
}

void bubbleSort(int sortingArray[], const int size)
{
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size - 1 - i; ++j) 
		{
			if (sortingArray[j] > sortingArray[j + 1])
			{
				swap(sortingArray[j], sortingArray[j + 1]);
			}
		}
	}
}