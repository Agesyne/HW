#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

const int debugCounter = 10;

double calculateResult(double argument)
{
	const double squareOfArgument = argument * argument;					//first multiplication
	return (squareOfArgument + 1) * (squareOfArgument + argument) + 1;		//(x^2 + 1)(x^2+x)+1. Here is second one
}

void printResult(double result)
{
	printf("Result: ");
	printf("%lf", result);
}

double getValue()
{
	double input = 0;
	printf("Enter \"x\" value: ");
	scanf("%lf", &input);
	return input;
}

void checkFunction()
{
	srand(1);
	for (int i = 0; i < debugCounter; i++)
	{
		const double x = rand() - rand();
		const double conditionCheck = fabs(x);
		const double checkResult = (x * x * x * x) + (x * x * x) + (x * x) + x + 1;

		if (fabs(checkResult - calculateResult(x)) > conditionCheck)
		{
			printf("Some mistakes here\n");
			printf("%lf\n", x);
			printf("%lf and %lf\n", checkResult, calculateResult(x));
			exit(1);
		}
	}
}

int main()
{
	checkFunction();
	double inputValue = getValue();

	double result = calculateResult(inputValue);

	printResult(result);
	return 0;
}