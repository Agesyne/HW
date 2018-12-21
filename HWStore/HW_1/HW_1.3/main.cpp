#include "pch.h"
#include <stdio.h>
#include <stdlib.h>

const int debugCounter = 10;
const int maximalLengthOfArray = 15;

void swap(int *first, int *second)
{
	int tmp = *second;
	*second = *first;
	*first = tmp;
}

void showArray(int arrayOfLines[], int lengthOfArray)
{
	printf("Result array: ");
	for (int i = 0; i < lengthOfArray; i++)
	{
		printf("%d ", arrayOfLines[i]);
	}
	printf("\n");
}

void reverseArrayOfLines(int arrayOfLines[], int lengthOfArray, int lengthOfFirstLine, int lengthOfSecondLine)
{
	for (int i = 0; i < lengthOfFirstLine / 2; i++)
	{
		swap(&arrayOfLines[i], &arrayOfLines[lengthOfFirstLine - 1 - i]);
	}

	for (int i = lengthOfFirstLine; i < lengthOfFirstLine + lengthOfSecondLine / 2; i++)
	{
		swap(&arrayOfLines[i], &arrayOfLines[lengthOfArray - 1 - i + lengthOfFirstLine]);
	}

	for (int i = 0; i < lengthOfArray / 2; i++)
	{
		swap(&arrayOfLines[i], &arrayOfLines[lengthOfArray - 1 - i]);
	}
}


int getValue(int number)
{
	int input = 0;
	printf("Enter length of %d-th line: ", number);
	scanf("%d", &input);
	return input;
}

void checkFunction()
{
	srand(1);
	for (int i = 0; i < debugCounter; i++)
	{
		const int lengthOfFirstLine = rand() % maximalLengthOfArray;
		const int lengthOfSecondLine = rand() % maximalLengthOfArray;

		const int fullLength = lengthOfFirstLine + lengthOfSecondLine;
		if (fullLength == 0)
		{
			continue;
		}
		int *arrayOfLines = new int[fullLength];

		for (int i = 0; i < lengthOfFirstLine; i++)
		{
			arrayOfLines[i] = lengthOfSecondLine + i;
		}
		for (int i = lengthOfFirstLine; i < fullLength; i++)
		{
			arrayOfLines[i] = i - lengthOfFirstLine;
		}

		reverseArrayOfLines(arrayOfLines, fullLength, lengthOfFirstLine, lengthOfSecondLine);
		for (int i = 0; i < fullLength; i++)
		{
			if (arrayOfLines[i] != i)
			{
				printf("Some mistakes here\n");
				printf("%d + %d = %d\n", lengthOfFirstLine, lengthOfSecondLine, fullLength);
				showArray(arrayOfLines, fullLength);
				exit(1);
			}
		}
		delete[] arrayOfLines;
	}
}

void enterLines(int arrayOfLines[], int lengthOfLine, int firstElement, int number)
{
	if (number == 1)
	{
		printf("Enter 1st line: ");
	}
	else
	{
		printf("Enter 2nd line: ");
	}

	for (int i = firstElement; i < lengthOfLine + firstElement; i++)
	{
		int tmp = 0;
		scanf("%d", &tmp);
		arrayOfLines[i] = tmp;
	}
	//printf("\n");
}

int main()
{
	checkFunction();
	const int lengthOfFirstLine = getValue(1);
	const int lengthOfSecondLine = getValue(2);

	const int lengthOfArray = lengthOfFirstLine + lengthOfSecondLine;
	if (lengthOfArray == 0)
	{
		printf("Array's length = 0");
		printf("%d + %d = %d\n", lengthOfFirstLine, lengthOfSecondLine, lengthOfArray);
		exit(1);
	}
	int *arrayOfLines = new int[lengthOfArray];

	enterLines(arrayOfLines, lengthOfFirstLine, 0, 1);
	enterLines(arrayOfLines, lengthOfSecondLine, lengthOfFirstLine, 2);

	reverseArrayOfLines(arrayOfLines, lengthOfArray, lengthOfFirstLine, lengthOfSecondLine);

	showArray(arrayOfLines, lengthOfArray);
	delete[] arrayOfLines;
	return 0;
}