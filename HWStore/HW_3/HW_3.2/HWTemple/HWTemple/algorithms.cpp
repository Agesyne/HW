#include "pch.h"
#include "main.h"
#include <stdio.h>


int partition(int sortingArray[], const int low, const int high)
{
	const int pivotElement = (sortingArray[low] + sortingArray[high] + sortingArray[(low + high) / 2]) / 3;

	int i = low;
	int j = high;

	while (i <= j)
	{
		while (sortingArray[i] < pivotElement)
		{
			i++;
		}

		while (pivotElement < sortingArray[j])
		{
			j--;
		}

		if (i >= j)
		{
			break;
		}

		swap(&sortingArray[i++], &sortingArray[j--]);
		//printArray(sortingArray, low, high);
	}
	return j;
}


void quickSort(int sortingArray[], const int low, const int high)
{
	if (low < high)
	{
		const int middle = partition(sortingArray, low, high);
		quickSort(sortingArray, low, middle);
		quickSort(sortingArray, middle + 1, high);
	}
}




bool binarySearch(int findingArray[], int number, int arraySize)
{
	int low = 0;
	int high = arraySize - 1;

	while (low <= high)
	{
		int mid = (low + high) / 2;
		if (findingArray[mid] == number)
		{
			return true;
		}
		
		if (number < findingArray[mid])
		{
			high = mid - 1;
		}
		else
		{
			low = mid + 1;
		}
	}

	return false;
}