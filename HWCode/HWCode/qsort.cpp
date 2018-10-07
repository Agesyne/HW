#include "pch.h"
#include "mainFunctions.h"
#include "insertionSort.h"
#include <iostream>

int partition(int sortingArray[], const int low, const int high, const int size)
{
	const int pivotElement = (sortingArray[low] + sortingArray[high] + sortingArray[(low + high) / 2]) / 3;

	int i = low - 1;
	int j = high + 1;

	while (1)
	{
		do
		{
			i++;
		} while (i < j && sortingArray[i] <= pivotElement);

		do
		{
			j--;
		} while (i < j && sortingArray[j] > pivotElement);

		if (i >= j)
		{
			if (sortingArray[j + 1] <= pivotElement)
			{
				j++;
			}
			if (sortingArray[j] > pivotElement)
			{
				j--;
			}
			return j;
		}

		swap(&sortingArray[i], &sortingArray[j]);
		//printArray(sortingArray, low, high);
	}
}

void quickSort(int sortingArray[], const int low, const int high, const int size)
{
	if (low < high)
	{
		if (high - low <= 10)
		{
			/*
			printf("\n");
			printArray(sortingArray, low, high);
			*/
			insertionSort(sortingArray, low, high, size);
			/*
			printArray(sortingArray, low, high);
			printf("\n");
			*/
		}
		else
		{
			const int middle = partition(sortingArray, low, high, size);
			quickSort(sortingArray, low, middle, size);
			quickSort(sortingArray, middle + 1, high, size);
		}
	}
}