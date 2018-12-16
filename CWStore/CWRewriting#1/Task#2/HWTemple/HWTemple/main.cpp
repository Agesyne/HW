#include "pch.h"
#include <iostream>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	autoGeneratedCheck();

	const int arrayLength = initNumber("Введите ко-во элементов массива: ");
	int *enteredArray = new int[arrayLength];

	initArray("Введите массив: ", enteredArray, arrayLength);

	shellSort(enteredArray, arrayLength);

	printf("Отсортированный массив: ");
	printArray(enteredArray, 0, arrayLength - 1);
	
	delete enteredArray;

	return 0;
}
