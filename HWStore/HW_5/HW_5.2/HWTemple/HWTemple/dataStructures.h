#pragma once

struct CyclicBiconnectedListElement
{
	int number;
	CyclicBiconnectedListElement *next;
	CyclicBiconnectedListElement *prev;
};

struct CyclicBiconnectedList
{
	CyclicBiconnectedListElement *head = nullptr;
	int size = 0;
};

bool isListEmpty(CyclicBiconnectedList *checkingList);

void addElementToList(CyclicBiconnectedList *addingList, int indexWhereAdd, int data);

int deleteElementFromList(CyclicBiconnectedList *deletingList, int numberWhatToDelete);

void deleteList(CyclicBiconnectedList *deletingList);

int getListSize(CyclicBiconnectedList *list);