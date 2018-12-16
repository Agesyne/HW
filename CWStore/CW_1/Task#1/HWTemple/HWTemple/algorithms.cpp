#include "pch.h"
#include "mainFunctions.h"


void printBitView(int givenArray[], const int arraySize, int number)
{
	int index = arraySize - 1;
	while (number > 0)
	{
		const int bit = number % 2;
		givenArray[index--] = bit;
		number /= 2;
	}
}

int compareBitView(int *firstArray, int *secondArray, int arraySize)
{
	for (int i = 0; i < arraySize; i++)
	{
		if (firstArray[i] != secondArray[i])
		{
			if (firstArray[i] > secondArray[i])
			{
				return 1;
			}
			else
			{
				return 2;
			}
		}
	}
	return 0;
}