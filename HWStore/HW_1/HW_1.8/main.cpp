#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int debugCounter = 10;
const int maxumalDebugNumber = 100;



void showResult(int result)
{
	printf("Number of zeros: %d", result);
	
}

int findNumberOfZeros(int arrayOfNumbers[], int sizeOfArray)
{
	int counter = 0;
	for (int i = 0; i < sizeOfArray; i++)
	{
		if (arrayOfNumbers[i] == 0)
		{
			counter++;
		}
	}
	return counter;
}

void initArray(int arrayOfNumbers[], int sizeOfArray)
{
	printf("Enter array separately: ");
	for (int i = 0; i < sizeOfArray; i++)
	{
		scanf("%d", &arrayOfNumbers[i]);
	}
}

void initNumber(int *number)
{
	printf("Enter number of elements: ");
	scanf("%d", number);
	return;
}

void checkFunction()
{
	srand(1);

	for (int i = 0; i < debugCounter; i++)
	{
		int counter = 0;
		int numberOfElements = rand() % maxumalDebugNumber;

		int *arrayOfNumbers = new int[numberOfElements];
		for (int j = 0; j < numberOfElements; j++)
		{
			int sharingNumber = rand() % maxumalDebugNumber;
			if (sharingNumber > 50)
			{
				arrayOfNumbers[j] = 1;
			}
			else
			{
				arrayOfNumbers[j] = 0;
				counter++;
			}
		}

		if (findNumberOfZeros(arrayOfNumbers, numberOfElements) != counter)
		{
			printf("Some mistakes here\n");
			printf("%d and %d: ", counter, findNumberOfZeros(arrayOfNumbers, numberOfElements));
			for (int j = 0; j < numberOfElements; j++)
			{
				printf("%d ", arrayOfNumbers[j]);
			}
			printf("\n");
			exit(1);
		}
	}
}

int main()
{
	checkFunction();
	int numberOfElements = 0;
	initNumber(&numberOfElements);

	int *arrayOfNumbers = new int[numberOfElements];
	initArray(arrayOfNumbers, numberOfElements);

	int numberOfZeros = findNumberOfZeros(arrayOfNumbers, numberOfElements);

	showResult(numberOfZeros);
	return 0;
}