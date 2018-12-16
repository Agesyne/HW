#include "pch.h"
#include "main.h"
#include "algorithms.h"
#include <iostream>

const int debugNumber = 10;
const int maxArraySize = 20;
const int maxCheckNumber = 30;
const int maxNumberInArray = 100;

void checkFunction()
{
	srand(0);

	for (int h = 0; h < debugNumber; h++)
	{
		const int arraySize = rand() % maxArraySize;
		const int checkNumber = rand() % maxCheckNumber;

		int *checkingArray = new int[arraySize];
		bool *isNumberInArray = new bool[maxNumberInArray];

		for (int i = 0; i < maxNumberInArray; i++)
		{
			isNumberInArray[i] = 0;
		}

		for (int i = 0; i < arraySize; i++)
		{
			const int randomNumber = rand() % maxNumberInArray;
			checkingArray[i] = randomNumber;
			isNumberInArray[randomNumber] = true;
		}

		quickSort(checkingArray, 0, arraySize - 1);
		//printArray(checkingArray, 0, arraySize - 1);

		

		for (int i = 0; i < checkNumber; i++)
		{
			const int randomNumber = rand() % maxNumberInArray;
			const bool isInArray = binarySearch(checkingArray, randomNumber, arraySize);
			
			if (isInArray != isNumberInArray[randomNumber])
			{
				printf("Mistake here\n");
				delete[] checkingArray;
				delete[] isNumberInArray;
				exit(1);
			}
		}

		delete[] checkingArray;
		delete[] isNumberInArray;
	}
}