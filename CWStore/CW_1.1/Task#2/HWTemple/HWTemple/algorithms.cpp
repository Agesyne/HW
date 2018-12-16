#include "pch.h"
#include <iostream>


void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int max(const int number1, const int number2)
{
	if (number2 < number1)
	{
		return number1;
	}
	else
	{
		return number2;
	}
}

void printArray(const int printingArray[], const int low, const int high)
{
	for (int i = low; i <= high; i++)
	{
		printf("%d ", printingArray[i]);
	}
	printf("\n");
}

void shellSort(int sortingArray[], const int size)
{
	int step = size;

	while (step > 0)
	{
		step /= 2;
		for (int i = step; i < size; ++i)
		{
			for (int j = i; j >= step; j-=step)
			{
				if (sortingArray[j - step] > sortingArray[j])
				{
					swap(&sortingArray[j], &sortingArray[j - step]);
				}
				else
				{
					break;
				}
			}
		}
	}
}