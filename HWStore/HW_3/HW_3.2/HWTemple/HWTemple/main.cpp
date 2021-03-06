#include "pch.h"
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
#include <iostream>
using namespace std;

const int maxNumberInArray = 1e9;

void printArray(const int sortingArray[], const int low, const int high)
{
	for (int i = low; i <= high; i++)
	{
		printf("%d ", sortingArray[i]);
	}
	printf("\n");
}


void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	checkFunction();
	srand(0);

	char text1[] = "Enter size of array: ";
	const int arraySize = initNumber(text1);

	char text2[] = "Enter number of checks: ";
	const int checkNumber = initNumber(text2);

	int *enteredArray = new int[arraySize];

	for (int i = 0; i < arraySize; i++)
	{
		const int randomNumber = rand() % maxNumberInArray;
		enteredArray[i] = randomNumber;
	}
	printArray(enteredArray, 0, arraySize - 1);

	quickSort(enteredArray, 0, arraySize - 1);

	for (int i = 0; i < checkNumber; i++)
	{
		int checkingNumber = rand() % maxNumberInArray;
		bool isInArray = binarySearch(enteredArray, checkingNumber, arraySize);
		printf("%d is ", checkingNumber);
		(isInArray) ? printf("IN") : printf("OFF");
		printf(" array\n");
	}

	delete[] enteredArray;

	return 0;
}
