#include "pch.h"
#include <iostream>
#include "dataStructures.h"

int initNumber(const char text[])
{
	int number = 0;
	printf("%s", text);
	scanf("%d", &number);
	return number;
}

void initArray(const char text[], int initingArray[], int arraySize)
{
	printf("%s", text);
	for (int i = 0; i < arraySize; i++)
	{
		int number = 0;
		scanf("%d", &number);
		initingArray[i] = number;
	}
}

void initListOfDeadmen(CyclicBiconnectedList *list, int numberOfDeadmen)
{
	for (int i = 1; i <= numberOfDeadmen; i++)
	{
		addElementToList(list, getListSize(list), i);
	}
}