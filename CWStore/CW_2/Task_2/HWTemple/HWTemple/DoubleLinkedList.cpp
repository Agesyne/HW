#include "pch.h"
#include "DoubleLinkedList.h"
#include <iostream>
using namespace std;

struct ListElement
{
	int data;
	ListElement *next;
	ListElement *prev;
};

bool DoubleLinkedList::isEmpty()
{
	return size == 0;
}


DoubleLinkedList::DoubleLinkedList()
{
	size = 0;
	head = nullptr;
	tail = nullptr;
}


DoubleLinkedList::~DoubleLinkedList()
{
}

void DoubleLinkedList::insertElementToList(const int data)
{
	if (isEmpty())
	{
		ListElement *newElement = new ListElement{ data, nullptr, nullptr };
		head = newElement;
		tail = newElement;
		size++;
		return;
	}

	ListElement *newElement = new ListElement{};
	newElement->data = data;
	for (ListElement *current = head; current != nullptr; current = current->next)
	{
		if (current->data < data)
		{
			if (current == tail)
			{
				newElement->prev = current;
				newElement->next = nullptr;
				current->next = newElement;
				tail = newElement;
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
				head = newElement;
			}
			else
			{
				newElement->prev->next = newElement;
			}
			break;
		}
	}
	size++;
}

void DoubleLinkedList::push_back(const int data)
{
	if (isEmpty())
	{
		ListElement *newElement = new ListElement{ data, nullptr, nullptr };
		head = newElement;
		tail = newElement;
		size++;
		return;
	}

	ListElement *newElement = new ListElement{data, nullptr, tail};
	tail->next = newElement;
	tail = newElement;
	size++;
}

void DoubleLinkedList::deleteElementFromList(const int data)
{
	if (isEmpty())
	{
		return;
	}
	if (size == 1 && head->data == data)
	{
		delete head;
		head = nullptr;
		tail = nullptr;
		size--;
		return;
	}
	for (ListElement *current = head; current != nullptr; current = current->next)
	{
		if (current->data == data)
		{
			if (current == head)
			{
				current->next->prev = nullptr;
				head = current->next;
			}
			else if (current == tail)
			{
				current->prev->next = nullptr;
				tail = current->prev;
			}
			else
			{
				current->next->prev = current->prev;
				current->prev->next = current->next;
			}
			delete current;
			size--;
			return;
		}
	}
}

void DoubleLinkedList::printAllData(bool isStraightOrder)
{
	if (isEmpty())
	{
		return;
	}

	if (isStraightOrder)
	{
		for (ListElement *current = head; current != nullptr; current = current->next)
		{
			cout << current->data << ' ';
		}
	}
	else
	{
		for (ListElement *current = tail; current != nullptr; current = current->prev)
		{
			cout << current->data << ' ';
		}
	}
	cout << endl;
}

void DoubleLinkedList::deleteAllList()
{
	if (isEmpty())
	{
		head = nullptr;
		tail = nullptr;
		return;
	}
	for (ListElement *current = head; current != nullptr; )
	{
		ListElement *deletingElement = current;
		current = current->next;
		delete deletingElement;
		size--;
	}
	head = nullptr;
	tail = nullptr;
}

ListElement *DoubleLinkedList::getHead()
{
	return head;
}

ListElement *DoubleLinkedList::getTail()
{
	return tail;
}

bool DoubleLinkedList::isSymmetric()
{
	auto i = head;
	auto j = tail;

	while (i != j)
	{
		if (i->data != j->data)
		{
			return false;
		}

		i = i->next;
		if (i == j)
		{
			break;
		}
		j = j->prev;
	}

	return true;
}