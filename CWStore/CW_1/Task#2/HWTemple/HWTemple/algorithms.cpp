#include "pch.h"
#include "mainFunctions.h"


void selectionSort(int sortingArray[], int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		int minElementIndex = arraySize - 1;
		for (int j = i; j < arraySize; j++)
		{
			if (sortingArray[j] < sortingArray[minElementIndex])
			{
				minElementIndex = j;
			}
		}
		swap(&(sortingArray[minElementIndex]), &(sortingArray[i]));
	}
}