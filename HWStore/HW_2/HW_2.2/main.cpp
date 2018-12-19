#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

const int debugCounter = 10;

int countLogarithmic(int number, int degree)
{
	if (number == 0 and degree == 0)
	{
		printf("0^0 = undefined\n");
		exit(1);
	}

	if (degree == 0)
	{
		return 1;
	}

	int result = 1;

	while (degree > 0)
	{
		if (degree & 1) //degree - нечётно
		{
			result *= number;
			degree--;
		}
		else
		{
			number *= number; //делаем по типу этого: 2^6 = 4^3
			degree >>= 1; // /2
		}
	}

	return result;
}

int countLinearly(const int number, const int degree)
{
	int result = 1;
	for (int i = 0; i < degree; i++)
	{
		result *= number;
	}
	return result;
}

void checkFunction()
{
	srand(1);
	for (int i = 0; i < debugCounter; i++)
	{
		const int number = rand() % 6;
		const int degree = rand() % 7;
		if (number + degree == 0)
		{
			continue;
		}
		const int linearlyResult = countLinearly(number, degree);
		const int logarithmicResult = countLogarithmic(number, degree);

		if (linearlyResult != logarithmicResult)
		{
			printf("Some mistakes here\n");
			exit(1);
		}
	}
}

void initNumber(int *number, int *degree)
{
	
	printf("Enter expression in the way (n^m): ");
	scanf("%d^%d", number, degree);
}

void showResult(const int number)
{
	printf("Result: %d", number);
}

int main()
{
	checkFunction();
	int number = 0;
	int degree = 0;
	initNumber(&number, &degree);

	const int result = countLogarithmic(number, degree);

	showResult(result);

	return 0;
}