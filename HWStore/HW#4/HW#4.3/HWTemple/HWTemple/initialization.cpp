#include "pch.h"
#include <iostream>

struct dictionaryRecord
{
	char name[100];
	char phoneNumber[15];
};

struct list
{
	list *next;
	list *prev;

	dictionaryRecord dictionaryRecord;
};

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