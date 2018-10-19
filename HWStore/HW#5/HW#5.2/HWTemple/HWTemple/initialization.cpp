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

void initListOfDeadmen(cyclicBiconnectedList *list, int numberOfDeadme)
{
	for (int i = 1; i <= numberOfDeadme; i++)
	{
		addElementToList(list, getListSize(list), i);
	}
}