#include "pch.h"
#include <iostream>

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




int getListSize(cyclicBiconnectedList *list)
{
	return list->size;
}

cyclicBiconnectedListElement *goAheadNTimes(cyclicBiconnectedListElement *currentElement, int numberHowManyTimesGo)
{
	for (int i = 0; i < numberHowManyTimesGo; i++)
	{
		currentElement = currentElement->next;
	}
	return currentElement;
}


bool isListEmpty(cyclicBiconnectedList *checkingList)
{
	if (checkingList->size > 0)
	{
		return false;
	}
	else
	{
		return true;
	}
}


void initList(cyclicBiconnectedList *addingList, int data)
{
	cyclicBiconnectedListElement *newListElement = new cyclicBiconnectedListElement{ data, nullptr, nullptr};
	newListElement->next = newListElement;
	newListElement->prev = newListElement;
	addingList->head = newListElement;
	addingList->size++;
}

void addElementToList(cyclicBiconnectedList *addingList, int indexWhereAdd, int data)
{
	//���� ��� ��������� - ������� � ���������� head
	if (isListEmpty(addingList))
	{
		initList(addingList, data);
		return;
	}

	addingList->size++;
	//�������� �������, ����� �������� ���������
	cyclicBiconnectedListElement *currentElement = goAheadNTimes(addingList->head, indexWhereAdd - 1);

	//������ ������� � ���������
	cyclicBiconnectedListElement *newListElement = new cyclicBiconnectedListElement{ data, currentElement->next, currentElement};
	currentElement->next->prev = newListElement;
	currentElement->next = newListElement;
}




int deleteHeadElementFromList(cyclicBiconnectedList *deletingList)
{
	int data = deletingList->head->number;
	if (getListSize(deletingList) == 1)
	{
		delete deletingList->head;
		deletingList->head = nullptr;
	}
	else
	{
		cyclicBiconnectedListElement *newHead = deletingList->head->next;
		newHead->prev = deletingList->head->prev;
		deletingList->head->prev->next = newHead;
		delete deletingList->head;
		deletingList->head = newHead;
	}
	return data;
}

int deleteElementFromList(cyclicBiconnectedList *deletingList, int numberWhatToDelete)
{
	//���� ��� ���������
	if (isListEmpty(deletingList))
	{
		printf("No elements in list\n");
		return -1;
	}

	int data = 0;
	//������� ���������
	cyclicBiconnectedListElement *deletingElement = goAheadNTimes(deletingList->head, numberWhatToDelete);

	//���� ������� ������
	if (deletingElement == deletingList->head)
	{
		data = deleteHeadElementFromList(deletingList);
		deletingList->size--;
		return data;
	}

	deletingList->size--;
	//�������
	data = deletingElement->number;
	deletingElement->next->prev = deletingElement->prev;
	deletingElement->prev->next = deletingElement->next;
	delete deletingElement;
	return data;
}

void deleteList(cyclicBiconnectedList *deletingList)
{
	while (!isListEmpty(deletingList))
	{
		deleteElementFromList(deletingList, 1);
	}
}
