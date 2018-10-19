#pragma once

struct cyclicBiconnectedListElement
{
	int number;
	cyclicBiconnectedListElement *next;
	cyclicBiconnectedListElement *prev;
};

struct cyclicBiconnectedList
{
	cyclicBiconnectedListElement *head;
	int size = 0;
};

bool isListEmpty(cyclicBiconnectedList *checkingList);

void addElementToList(cyclicBiconnectedList *addingList, int indexWhereAdd, int data);

int deleteElementFromList(cyclicBiconnectedList *deletingList, int numberWhatToDelete);

void deleteList(cyclicBiconnectedList *deletingList);

int getListSize(cyclicBiconnectedList *list);