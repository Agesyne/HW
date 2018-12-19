#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

const int debugCounter = 10;



int calculateResult(int more, int less)
{
	if (less == 0)
	{
		printf("error: division by 0");
		exit(1);
	}
	if (more == 0 || (more * less > 0 && abs(less) > abs(more)))
	{
		return 0;
	}

	bool isCrossSign = false;
	if (more * less < 0)
	{
		isCrossSign = true;
	}

	int counter = 0;
	
	more = abs(more);
	less = abs(less);
	while (more >= less)
	{
		more -= less;
		counter++;
	}

	if (isCrossSign)
	{
		return -counter;
	}
	return counter;
	
}

void printResult(int result)
{
	printf("Result: ");
	printf("%d", result);
}

void getValue(int *inputA, int *inputB)
{
	printf("Enter \"a\" and \"b\" values, where a >= b: ");
	scanf("%d %d", inputA, inputB);
	return;
}

void checkFunction()
{
	srand(1);
	for (int i = 0; i < debugCounter; i++)
	{
		int more = rand() - rand();
		int less = rand() - rand();
		if (less == 0)
		{
			continue;
		}
		
		int checkRes = more / less;
		//printf("%d, %d\n", more, less);
		if (checkRes != calculateResult(more, less))
		{
			printf("Some mistakes here\n");
			printf("%d and %d\n", checkRes, calculateResult(more, less));
			exit(1);
		}
	}
}

int main()
{
	checkFunction();
	int inputValueA = 0, inputValueB = 0;
	getValue(&inputValueA, &inputValueB);

	int result = calculateResult(inputValueA, inputValueB);

	printResult(result);
	return 0;
}