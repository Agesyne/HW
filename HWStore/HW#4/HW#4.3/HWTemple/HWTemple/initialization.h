#pragma once

int initNumber(const char[]);

void initArray(const char text[], int initingArray[], int arraySize);

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