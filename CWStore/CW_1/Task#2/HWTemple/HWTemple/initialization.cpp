#include "pch.h"
#include <iostream>

int initNumber(char text[])
{
	int number = 0;
	printf("%s", text);
	scanf("%d", &number);
	return number;
}

void initArray(int enteringArray[], int arraySize)
{
	printf("Enter array: ");
	for (int i = 0; i < arraySize; i++)
	{
		int number = 0;
		scanf("%d", &number);
		enteringArray[i] = number;
	}
}