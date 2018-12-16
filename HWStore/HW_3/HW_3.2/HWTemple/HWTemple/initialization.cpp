#include "pch.h"
#include <stdio.h>

int initNumber(char text[])
{
	int number = 0;
	printf("%s", text);
	scanf("%d", &number);
	return number;
}

void initArray(int initialisingArray[], int arraySize)
{
	printf("Enter the array: ");
	for (int i = 0; i < arraySize; i++)
	{
		int number = 0;
		scanf("%d", &number);
		initialisingArray[i] = number;
	}
}