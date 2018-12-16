#include "pch.h"
#include <iostream>
#include <string.h>

int initNumber(char text[])
{
	int number = 0;
	printf("%s", text);
	scanf("%d", &number);
	return number;
}

int initArray(const char text[], int **enteringArray)
{
	printf("%s", text);
	char stringArray[100];
	scanf("%s", stringArray);

	int counter = 0;
	while (stringArray[counter] == '0')
	{
		counter++;
	}
	//00110
	//01234
	const int length = strlen(stringArray) - counter;
	*enteringArray = new int[length];

	for (int i = 0; i < length; i++)
	{
		(*enteringArray)[i] = stringArray[i + counter];
	}
	return length;
}