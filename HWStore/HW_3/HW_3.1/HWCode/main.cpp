#include "pch.h"
#include "qsort.h"
#include "check.h"
#include "initialization.h"
#include <iostream>

void printArray(const int printingArray[], const int low, const int high)
{
	for (int i = low; i <= high; i++)
	{
		printf("%d ", printingArray[i]);
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

	const int arraySize = initNumber();
	int *sortingArray = new int[arraySize];

	initArray(sortingArray, arraySize);

	quickSort(sortingArray, 0, arraySize - 1, arraySize);
	
	printf("Sorted array: ");
	printArray(sortingArray, 0, arraySize - 1);

	delete[] sortingArray;
	return 0;
}
