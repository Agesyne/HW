#pragma once

int initNumber(const char[]);

void initArray(const char text[], int initingArray[], int arraySize);

struct DictionaryRecord
{
	char name[100];
	char phoneNumber[15];
};

struct List
{
	List *next;
	List *prev;

	DictionaryRecord data;
};