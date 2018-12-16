#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

const int debugCounter = 10;

int recursizeFibonachi(const int number)
{
	if (number <= 1)
	{
		return number;
	}
	else
	{
		return recursizeFibonachi(number - 1) + recursizeFibonachi(number - 2);
	}
}

int linearlyFibonachi(const int number)
{
	if (number <= 1)
	{
		return number;
	}

	int next = 1;
	int current = 1;

	for (int i = 0; i < number - 1; i++)
	{
		int tmp = next;
		next += current;
		current = tmp;
	}

	return current;
}

void checkFunction()
{
	srand(0);
	for (int i = 0; i < debugCounter; i++)
	{
		const int number = rand() % 38;
		const int recursiveResult = recursizeFibonachi(number);
		const int linearlyResult = linearlyFibonachi(number);

		if (recursiveResult != linearlyResult)
		{
			printf("Some mistakes here\n");
			exit(1);
		}
	}
}

int initNumber()
{
	int number = 0;
	printf("Enter number of Fibonachi: ");
	scanf("%d", &number);
	return number;
}

void showResult(const int number)
{
	printf("N-th Fibonachi number: %d", number);
}

int main()
{
	checkFunction();
	const int number = initNumber();
	const int linearlyResult = linearlyFibonachi(number);

	showResult(linearlyResult);


	return 0;
}