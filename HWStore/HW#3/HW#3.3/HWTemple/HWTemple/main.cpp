#include "pch.h"
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
#include <iostream>
using namespace std;

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	checkFromFile();

	const int arraySize =  initNumber("Enter array size: ");
	int *enteredArray = new int[arraySize];


	initArray("Enter array: ", enteredArray, arraySize);

	quickSort(enteredArray, 0, arraySize - 1);

	const int maxFrequencyNumber = findMaxFrequencyNumber(enteredArray, arraySize);

	printf("Max frequency number: %d", maxFrequencyNumber);

	delete[] enteredArray;
	return 0;
}
