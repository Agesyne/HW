#include "pch.h"
#include <iostream>
#include "mainFunctions.h"

void insertionSort(int sortingArray[], const int low, const int high)
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
		if (high - low <= 10)
		{
			/*
			printf("\n");
			printArray(sortingArray, low, high);
			*/
			insertionSort(sortingArray, low, high);
			/*
			printArray(sortingArray, low, high);
			printf("\n");
			*/
		}
		else
		{
			const int middle = partition(sortingArray, low, high);
			quickSort(sortingArray, low, middle);
			quickSort(sortingArray, middle + 1, high);
		}
	}
}

void processInputString(const char buffer[], int *enteredArray[], int *arraySize)
{

	bool isArrayBegun = false;	
	int arrayIndex = 0;

	bool isNumberNext = false;	
	int numberCounter = 0;


	for (int charCounter = 0; buffer[charCounter] != '\n' && buffer[charCounter] != '\0'; charCounter++)
	{
		if (buffer[charCounter] == '=')
		{
			isNumberNext = true;
			numberCounter++;
			charCounter++;
			continue;
		}

		if (isArrayBegun && buffer[charCounter] == ' ')
		{
			isNumberNext = true;
			continue;
		}

		if (isNumberNext)
		{
			int digitLength = 0;
			for (int i = 0;;)
			{
				if (isdigit(buffer[charCounter + i]))
				{
					i++;
				}
				else
				{
					digitLength = i;
					break;
				}
			}

			int numberFromString = 0;
			for (int i = 0; i < digitLength; i++)
			{
				numberFromString = numberFromString * 10 + (buffer[charCounter + i] - '0');
			}

			if (!isArrayBegun)
			{
				switch (numberCounter)
				{
				case 1:
					*arraySize = numberFromString;
					*enteredArray = new int[*arraySize];
					break;
				}
			}
			else
			{
				(*enteredArray)[arrayIndex++] = numberFromString;
			}

			charCounter += digitLength - 1;
			isNumberNext = false;
			continue;
		}

		if (buffer[charCounter] == ':')
		{
			isArrayBegun = true;
		}

	}
}

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

void printArray(const int printingArray[], const int low, const int high, const char text[])
{
	printf("%s", text);
	for (int i = low; i <= high; i++)
	{
		printf("%d ", printingArray[i]);
	}
	printf("\n");
}