#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctime>

const int debugCounter = 10;
const int maxDebugArraySize = 10;
const int maxDebugNumberInArray = 50;



void showResult(int transformingArray[], const int sizeOfArray)
{
	printf("Sorted array: ");
	for (int i = 0; i < sizeOfArray; i++)
	{
		printf("%d ", transformingArray[i]);
	}
	printf("\n");
}

void swap(int *firstElement, int *secondElement)
{
	int tmp = *firstElement;
	*firstElement = *secondElement;
	*secondElement = tmp;
}

void arrayTratsformition(int *transformingArray, const int sizeOfArray, const int firstElement)
{
	int i = 1;
	int j = sizeOfArray - 1;
	while (i < j)
	{
		while (transformingArray[i] < firstElement && i < j)
		{
			i++;
		}
		while (transformingArray[j] >= firstElement && i < j)
		{
			j--;
		}
		if (i < j)
		{
			swap(&transformingArray[i], &transformingArray[j]);
			i++;
			j--;
		}
		//showResult(transformingArray, sizeOfArray);
	}
	
	//showResult(transformingArray, sizeOfArray);
	i = 1;
	while (transformingArray[i] < firstElement and i < sizeOfArray)
	{
		i++;
	}
	i--;
	
	if (i != sizeOfArray)
	{
		swap(&transformingArray[0], &transformingArray[i]);
	}
	//showResult(transformingArray, sizeOfArray);
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



		const int firstElement = debugArray[0];

		arrayTratsformition(debugArray, sizeOfArray, firstElement);

		bool isWellTransformed = true;
		bool isBeforeFirstElement = true;
		for (int j = 0; j < sizeOfArray; j++)
		{
			if (debugArray[j] == firstElement)
			{
				isBeforeFirstElement = false;
			}
			if (isBeforeFirstElement)
			{
				if (debugArray[j] >= firstElement)
				{
					isWellTransformed = false;
				}
			}
			else
			{
				if (debugArray[j] < firstElement)
				{
					isWellTransformed = false;
				}
			}
		}


		//showResult(debugArray, sizeOfArray);
		if (!isWellTransformed)
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

	const int firstElement = sortingArray[0];

	arrayTratsformition(sortingArray, sizeOfArray, firstElement);


	showResult(sortingArray, sizeOfArray);

	delete[] sortingArray;

	return 0;
}