#include "pch.h"
#include <iostream>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
#include "readFile.h"

void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main()
{
	setlocale(LC_ALL, "RUS");
	checkFromFile();

	char *data[100] = {};
	const int linesRead = readFile("Data.txt", data);

	for (int linesCounter = 0; linesCounter < linesRead; linesCounter++)
	{
		char *buffer = data[linesCounter];
		int *enteredArray = nullptr;
		int arraySize = 0;

		processInputString(buffer, &enteredArray, &arraySize);

		quickSort(enteredArray, 0, arraySize - 1);

		printArray(enteredArray, 0, arraySize - 1, "Отсортированный массив: ");

		delete[] enteredArray;
		delete[] data[linesCounter];
	}

	return 0;
}
