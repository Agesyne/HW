#include "pch.h"
#include "mainFunctions.h"

void insertionSort(int sortingArray[], const int low, const int high, const int size)
{
	for (int i = low + 1; i <= high; i++)
	{
		int key = sortingArray[i];
		int j = i - 1;
		while (j >= low && key < sortingArray[j])
		{
			sortingArray[j + 1] = sortingArray[j];
			j--;
		}
		sortingArray[j + 1] = key;
		//printArray(sortingArray, 0, size - 1);
	}
}