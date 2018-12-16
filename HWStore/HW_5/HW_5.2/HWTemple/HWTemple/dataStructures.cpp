#include "pch.h"
#include <iostream>
#include "dataStructures.h"




int getListSize(CyclicBiconnectedList *list)
{
	return list->size;
}

CyclicBiconnectedListElement *goAheadNTimes(CyclicBiconnectedListElement *currentElement, int numberHowManyTimesGo)
{
	for (int i = 0; i < numberHowManyTimesGo; i++)
	{
		currentElement = currentElement->next;
	}
	return currentElement;
}


bool isListEmpty(CyclicBiconnectedList *checkingList)
{
	return !(checkingList->size > 0);
}


void initList(CyclicBiconnectedList *addingList, int data)
{
	CyclicBiconnectedListElement *newListElement = new CyclicBiconnectedListElement{ data, nullptr, nullptr};
	newListElement->next = newListElement;
	newListElement->prev = newListElement;
	addingList->head = newListElement;
	addingList->size++;
}

void addElementToList(CyclicBiconnectedList *addingList, int indexWhereAdd, int data)
{
	//если нет элементов - добавим с изменением head
	if (isListEmpty(addingList))
	{
		initList(addingList, data);
		return;
	}

	addingList->size++;
	//вычислим элемент, после которого добавляем
	CyclicBiconnectedListElement *currentElement = goAheadNTimes(addingList->head, indexWhereAdd - 1);

	//создаём элемент и вставляем
	auto newListElement = new CyclicBiconnectedListElement{ data, currentElement->next, currentElement};
	currentElement->next->prev = newListElement;
	currentElement->next = newListElement;
}




int deleteHeadElementFromList(CyclicBiconnectedList *deletingList)
{
	int data = deletingList->head->number;
	if (getListSize(deletingList) == 1)
	{
		delete deletingList->head;
		deletingList->head = nullptr;
	}
	else
	{
		CyclicBiconnectedListElement *newHead = deletingList->head->next;
		newHead->prev = deletingList->head->prev;
		deletingList->head->prev->next = newHead;
		delete deletingList->head;
		deletingList->head = newHead;
	}
	return data;
}

int deleteElementFromList(CyclicBiconnectedList *deletingList, int numberWhatToDelete)
{
	//если нет элементов
	if (isListEmpty(deletingList))
	{
		printf("No elements in list\n");
		return -1;
	}

	int data = 0;
	//находим удаляемый
	CyclicBiconnectedListElement *deletingElement = goAheadNTimes(deletingList->head, numberWhatToDelete);

	//если удаляем голову
	if (deletingElement == deletingList->head)
	{
		data = deleteHeadElementFromList(deletingList);
		deletingList->size--;
		return data;
	}

	deletingList->size--;
	//удаляем
	data = deletingElement->number;
	deletingElement->next->prev = deletingElement->prev;
	deletingElement->prev->next = deletingElement->next;
	delete deletingElement;
	return data;
}

void deleteList(CyclicBiconnectedList *deletingList)
{
	while (!isListEmpty(deletingList))
	{
		deleteElementFromList(deletingList, 1);
	}
}
