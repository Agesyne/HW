#include "pch.h"
#include <iostream>

int initNumber()
{
	int number = 0;
	printf("Enter size of array: ");
	scanf("%d", &number);
	return number;
}

void initArray(int givenArray[], int size)
{
	printf("Enter array: ");
	for (int i = 0; i < size; i++)
	{
		int number = 0;
		scanf("%d", &number);
		givenArray[i] = number;
	}
}