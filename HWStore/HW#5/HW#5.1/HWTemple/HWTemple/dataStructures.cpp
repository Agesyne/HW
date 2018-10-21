#include "pch.h"
#include <stdio.h>

struct ListElement
{
	int data;
	ListElement *next;
	ListElement *prev;
};

struct DoubleLinkedList
{
	int size = 0;
	ListElement *head = nullptr;
	ListElement *tail = nullptr;
};


bool isEmpty(DoubleLinkedList *list)
{
	return list->size == 0;
}


void insertElementToList(DoubleLinkedList *list, const int data, void(*printData)(const int data) = nullptr)
{
	if (isEmpty(list))
	{
		ListElement *newElement = new ListElement{ data, nullptr, nullptr };
		list->head = newElement;
		list->tail = newElement;
		if (printData != nullptr)
		{
			printData(data);
		}
		list->size++;
		return;
	}
	
	ListElement *newElement = new ListElement{};
	newElement->data = data;

	for (ListElement *current = list->head; current != nullptr; current = current->next)
	{
		if (current->data < data)
		{
			if (current == list->tail)
			{
				newElement->prev = current;
				newElement->next = nullptr;
				current->next = newElement;
				list->tail = newElement;
				break;
			}
			continue;
		}
		else
		{
			newElement->next = current;
			newElement->prev = current->prev;
			current->prev = newElement;
			if (newElement->prev == nullptr)
			{
				list->head = newElement;
			}
			else
			{
				newElement->prev->next = newElement;
			}
			break;
		}
	}

	if (printData != nullptr)
	{
		printData(data);
	}
	list->size++;
}

void deleteElmentFromList(DoubleLinkedList *list, const int data, void(*printData)(const int data, bool hasFound) = nullptr)
{
	if (isEmpty(list))
	{
		printf("Пустой список\n");
		return;
	}

	if (list->size == 1 && list->head->data == data)
	{
		delete list->head;
		list->head = nullptr;
		list->tail = nullptr;
		if (printData != nullptr)
		{
			printData(data, true);
		}
		list->size--;
		return;
	}

	for (ListElement *current = list->head; current != nullptr; current = current->next)
	{
		if (current->data == data)
		{
			if (current == list->head)
			{
				current->next->prev = nullptr;
				list->head = current->next;
			}
			else if (current == list->tail)
			{
				current->prev->next = nullptr;
				list->tail = current->prev;
			}
			else
			{
				current->next->prev = current->prev;
				current->prev->next = current->next;
			}

			delete current;
			printData(data, true);
			list->size--;
			return;
		}
	}

	printData(data, false);
}

void printAllData(DoubleLinkedList *list, bool isStraightOrder = true)
{
	if (isEmpty(list))
	{
		printf("Пустой список\n");
		return;
	}

	if (isStraightOrder)
	{
		for (ListElement *current = list->head; current != nullptr; current = current->next)
		{
			printf("%d ", current->data);
		}
	}
	else
	{
		for (ListElement *current = list->tail; current != nullptr; current = current->prev)
		{
			printf("%d ", current->data);
		}
	}
	printf("\n");
}

void deleteAllList(DoubleLinkedList *list)
{
	if (isEmpty(list))
	{
		list->head = nullptr;
		list->tail = nullptr;
		return;
	}

	for (ListElement *current = list->head; current != nullptr; )
	{
		ListElement *deletingElement = current;
		current = current->next;
		delete deletingElement;
		list->size--;
	}

	list->head = nullptr;
	list->tail = nullptr;
}