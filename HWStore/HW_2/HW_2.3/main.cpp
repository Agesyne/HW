#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

const int debugCounter = 10;
const int maxDebugArraySize = 100;
const int maxDebugNumberInArray = 100;

void swap(int *firstElement, int *secondElement)
{
	int tmp = *firstElement;
	*firstElement = *secondElement;
	*secondElement = tmp;
}

void showResult(int *sortingArray, const int sizeOfArray)
{
	printf("Sorted array: ");
	for (int i = 0; i < sizeOfArray; i++)
	{
		printf("%d ", sortingArray[i]);
	}
	printf("\n");
}

void bubbleSort(int sortingArray[], const int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		for (int j = 0; j < sizeOfArray - i - 1; j++)
		{
			if (sortingArray[j] > sortingArray[j + 1])
			{
				swap(&sortingArray[j], &sortingArray[j + 1]);
			}
		}
	}
}

void countingSort(int sortingArray[], const int sizeOfArray)
{
	int lowestElement = INT_MAX;
	int highestElement = INT_MIN;
	for (int i = 0; i < sizeOfArray; i++)
	{
		if (sortingArray[i] > highestElement)
		{
			highestElement = sortingArray[i];
		}
		if (sortingArray[i] < lowestElement)
		{
			lowestElement = sortingArray[i];
		}
	}

	const int rangeOfSortingArray = highestElement - lowestElement + 1;
	int *countingSortArray = new int[rangeOfSortingArray] {};

	for (int i = 0; i < sizeOfArray; i++)
	{
		int index = sortingArray[i] - lowestElement;
		countingSortArray[index]++;
	}
	//showResult(countingSortArray, rangeOfSortingArray);

	int j = 0;
	for (int i = 0; i < rangeOfSortingArray; i++)
	{
		while (countingSortArray[i] > 0)
		{
			sortingArray[j] = i + lowestElement;
			j++;
			countingSortArray[i]--;
		}
	}
	delete[] countingSortArray;
}

void checkFunction()
{
	srand(0);
	for (int i = 0; i < debugCounter; i++)
	{
		const int sizeOfArray = rand() % maxDebugArraySize + 1;
		int *debugArray = new int[sizeOfArray];

		for (int j = 0; j < sizeOfArray; j++)
		{
			debugArray[j] = rand() % maxDebugNumberInArray - rand() % maxDebugNumberInArray;
		}
		//showResult(debugArray, sizeOfArray);

		if (i & 1)
		{
			bubbleSort(debugArray, sizeOfArray);
		}
		else
		{
			countingSort(debugArray, sizeOfArray);
		}

		bool isSorted = true;
		for (int j = 0; j < sizeOfArray - 1; j++)
		{
			if (debugArray[j] > debugArray[j + 1])
			{
				isSorted = false;
				break;
			}
		}

		if (!isSorted)
		{
			printf("Some mistakes here\n");
			showResult(debugArray, sizeOfArray);
			delete[] debugArray;
			exit(1);
		}
		delete[] debugArray;
	}
}

void initArray(int *sortingArray, const int sizeOfArray)
{
	printf("Enter elements of array: ");
	for (int i = 0; i < sizeOfArray; i++)
	{
		scanf("%d", &sortingArray[i]);
	}
}

int initNumber()
{
	int number = 0;
	printf("Enter size of array: ");
	scanf("%d", &number);
	return number;
}


int main()
{
	checkFunction();
	
	int sizeOfArray = initNumber();

	int *sortingArray = new int[sizeOfArray];

	initArray(sortingArray, sizeOfArray);

	srand(time(0));
	int chooseWayOfSort = rand() & 100;

	if (chooseWayOfSort > 50)
	{
		printf("bubbleSort\n");
		bubbleSort(sortingArray, sizeOfArray);
	}
	else
	{
		printf("countingSort\n");
		countingSort(sortingArray, sizeOfArray);
	}


	showResult(sortingArray, sizeOfArray);

	delete[] sortingArray;

	return 0;
}