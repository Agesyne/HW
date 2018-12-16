#include "pch.h"
#include <iostream>

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int partition(int sortingArray[], const int low, const int high)
{
	const int pivotNumber = (sortingArray[low] + sortingArray[(low + high) / 2] + sortingArray[high]) / 3;
	int i = low;
	int j = high;

	while (i <= j)
	{
		while (sortingArray[i] < pivotNumber)
		{
			i++;
		}

		while (pivotNumber < sortingArray[j])
		{
			j--;
		}

		if (i >= j)
		{
			break;
		}

		swap(&sortingArray[i++], &sortingArray[j--]);
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


int findMaxFrequencyNumber(int enteredArray[], const int arraySize)
{
	int maxFrequencyNumber = -1;
	int maxFrequency = -1;
	int i = 0;
	while (i < arraySize)
	{
		int number = enteredArray[i];
		int counter = 0;

		while (enteredArray[i] == number)
		{
			counter++;
			i++;
		}

		if (maxFrequency < counter)
		{
			maxFrequency = counter;
			maxFrequencyNumber = number;
		}
	}
	return maxFrequencyNumber;
}

void processInputString(const char buffer[], int *enteredArray[], int *arraySize, int *result)
{
	int arrayBeginning = 0;
	sscanf(buffer, "Size = %d, Result = %d:%n", arraySize, result, &arrayBeginning);
	*enteredArray = new int[*arraySize];

	int cumulativeSum = 0;
	for (int i = 0; i < *arraySize; ++i)
	{
		int number = 0;
		int offset = 0;

		sscanf(buffer + arrayBeginning + cumulativeSum, " %d%n", &number, &offset);
		cumulativeSum += offset;

		(*enteredArray)[i] = number;
	}
}