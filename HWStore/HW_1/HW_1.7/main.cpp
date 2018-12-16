#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int debugCounter = 10;
const int maxumalDebugNumber = 100;



void showResult(bool arrayOfPrime[], int sizeOfArray)
{
	printf("Prime numbers: ");
	for (int i = 2; i < sizeOfArray; i++)
	{
		if (arrayOfPrime[i])
		{
			printf("%d ", i);
		}
	}
	printf("\n");
}

void findPrime(bool arrayOfPrime[], int sizeOfArray)
{
	for (int i = 2; i <= sqrt(sizeOfArray); i++)
	{
		if (arrayOfPrime[i])
		{
			for (int j = i + 1; j < sizeOfArray; j++)
			{
				if (j % i == 0)
				{
					arrayOfPrime[j] = false;
				}
			}
		}
	}
}

void initArray(bool arrayOfPrime[], int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		arrayOfPrime[i] = true;
	}
}

void initNumber(int *number)
{
	printf("Enter maximal number: ");
	scanf("%d", number);
}

void checkFunction()
{
	srand(1);

	for (int i = 0; i < debugCounter; i++)
	{
		const int number = rand() % 100 + 1;
		bool *arrayOfPrime = new bool[number];

		findPrime(arrayOfPrime, number);

		for (int i = 2; i < number; i++)
		{
			bool isWrong = false;
			if (arrayOfPrime[i])
			{
				for (int j = 2; j <= sqrt(i); j++)
				{
					if (i % j == 0)
					{
						isWrong = true;
						break;
					}
				}
			}

			if (isWrong)
			{
				printf("Some mistakes here\n");
				exit(1);
			}
		}
		delete[] arrayOfPrime;
	}
}

int main()
{
	checkFunction();
	int maximalNumber = 0;
	initNumber(&maximalNumber);

	bool *primeNumberArray = new bool[maximalNumber + 1];
	initArray(primeNumberArray, maximalNumber + 1);

	findPrime(primeNumberArray, maximalNumber + 1);

	showResult(primeNumberArray, maximalNumber + 1);
	delete[] primeNumberArray;
	return 0;
}