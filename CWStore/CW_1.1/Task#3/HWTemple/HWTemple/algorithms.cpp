#include "pch.h"
#include <iostream>
#include "algorithms.h"


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

void processInputString(const char buffer[])
{
	bool isCommentHere = false;
	for (int charCounter = 0; buffer[charCounter] != '\n' && buffer[charCounter] != '\0'; charCounter++)
	{
		if (buffer[charCounter] == ';')
		{
			isCommentHere = true;
		}

		if (isCommentHere)
		{
			printf("%c", buffer[charCounter]);
		}
	}
	if (isCommentHere)
	{
		printf("\n");
	}
}