#include "pch.h"
#include "SinglyConnectedList.h"
#include <iostream>
using namespace std;

struct ListElement
{
	int data;
	ListElement *next;
};

int SinglyConnectedList::getSize()
{
	return size;
}

ListElement *SinglyConnectedList::getHead()
{
	return head;
}

SinglyConnectedList::SinglyConnectedList()
{
}

void SinglyConnectedList::push_back(const int data)
{
	++size;
	ListElement *newListElement = new ListElement{ data, nullptr };
	if (head == nullptr)
	{
		head = newListElement;
		return;
	}


	ListElement *current = head;
	while (current->next != nullptr)
	{
		current = current->next;
	}

	current->next = newListElement;
}

void SinglyConnectedList::deleteList()
{
	if (head == nullptr)
	{
		return;
	}

	ListElement *nextDeletingElement = head;
	while (nextDeletingElement != nullptr)
	{
		nextDeletingElement = head->next;
		delete head;
		head = nextDeletingElement;
	}

	head = nullptr;
	size = 0;
}

void SinglyConnectedList::reverse()
{
	if (size <= 1)
	{
		return;
	}

	ListElement *nextReversingElement = head->next;
	ListElement *prevReversingElement = nullptr;
	while (nextReversingElement != nullptr)
	{
		head->next = prevReversingElement;
		prevReversingElement = head;
		head = nextReversingElement;
		nextReversingElement = head->next;
	}
	head->next = prevReversingElement;
}

void SinglyConnectedList::print()
{
	ListElement *current = head;
	while (current != nullptr)
	{
		cout << current->data << " -> ";
		current = current->next;
	}
	cout << "[]" << endl;
}

bool SinglyConnectedList:: operator== (SinglyConnectedList &list1)
{
	if (getSize() != list1.getSize())
	{
		return false;
	}

	ListElement *firstListElement = list1.getHead();
	ListElement *secondListElement = getHead();

	while (firstListElement != nullptr || secondListElement != nullptr)
	{
		if (firstListElement->data != secondListElement->data)
		{
			return false;
		}
	}

	return true;
}

SinglyConnectedList::~SinglyConnectedList()
{
	deleteList();
}
