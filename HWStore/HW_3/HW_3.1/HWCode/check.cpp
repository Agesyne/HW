#include "pch.h"
#include "qsort.h"
#include "main.h"
#include <iostream>

const int debugNumber = 100;
const int maxArraySize = 100;
const int maxRandomArrayElement = 100;


bool isSorted(int checkingArray[], int size)
{
	bool isSortedArray = true;
	for (int i = 1; i < size; i++)
	{
		if (checkingArray[i - 1] > checkingArray[i])
		{
			isSortedArray = false;
			break;
		}
	}

	return isSortedArray;
}

void checkFunction()
{
	srand(0);

	for (int i = 0; i < debugNumber; i++)
	{
		const int arraySize = rand() % maxArraySize;
		int *checkingArray = new int[arraySize];

		for (int j = 0; j < arraySize; j++)
		{
			checkingArray[j] = rand() % maxRandomArrayElement;
		}

		//printf("Checking the array:\n");
		//printArray(checkingArray, 0, arraySize - 1);

		quickSort(checkingArray, 0, arraySize - 1, arraySize);

		if (!isSorted(checkingArray, arraySize))
		{
			printf("The array wasn't sorted:\n");
			printArray(checkingArray, 0, arraySize - 1);
			delete[] checkingArray;
			exit(1);
		}
		//printf("The array sorted correctly:\n");
		//printArray(checkingArray, 0, arraySize - 1);

		delete[] checkingArray;
	}
}