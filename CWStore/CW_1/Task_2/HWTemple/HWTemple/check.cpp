#include "pch.h"
#include <iostream>
#include "mainFunctions.h"
#include "algorithms.h"

const int debugNumber = 10;
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

		selectionSort(checkingArray, arraySize);

		if (!isSorted(checkingArray, arraySize))
		{
			printf("The array wasn't sorted:\n");
			printArray(checkingArray, arraySize);
			delete[] checkingArray;
			exit(1);
		}
		delete[] checkingArray;
	}
}

void checkFromFile()
{
	FILE *inputDataFile = fopen("data.txt", "r");
	if (!inputDataFile)
	{
		printf("File not fount");
		exit(1);
	}

	char *data[100] = {};
	int linesRead = 0;

	while (!feof(inputDataFile))
	{
		char *buffer = new char[100];
		const int readBytes = fscanf(inputDataFile, "%[^\n]", buffer);
		if (readBytes < 0)
		{
			break;
		}
		data[linesRead++] = buffer;
	}

	for (int linesCounter = 0; linesCounter < linesRead; linesCounter++)
	{
		
	}

	
	fclose(inputDataFile);
}