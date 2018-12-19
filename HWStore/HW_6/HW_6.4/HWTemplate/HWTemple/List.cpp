#include "pch.h"
#include "List.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct ListElement
{
	string name;
	string phoneNumber;
	ListElement *prev;
	ListElement *next;
};

List::List()
{
}


List::~List()
{
	deleteList();
}

// Begin with 0
ListElement *List::at(const int number) const
{
	if (number >= size)
	{
		return nullptr;
	}

	ListElement *current = head;
	for (int i = 0; i < number; ++i)
	{
		current = current->next;
	}

	return current;
}

void List::pushBack(const string &name, const string &phoneNumber)
{
	auto newRecord = new ListElement{ name, phoneNumber, tail , nullptr };
	if (head == nullptr)
	{
		head = newRecord;
	}
	else
	{
		tail->next = newRecord;
	}
	tail = newRecord;
	++size;
}

//true <=> 1-й больше
bool compareRecords(const ListElement &record1, const ListElement &record2, const bool isOrderByNames)
{
	if (isOrderByNames)
	{
		return record1.name > record2.name;
	}
	else
	{
		return record1.phoneNumber > record2.phoneNumber;
	}
}

List *List::merge(const int low, const int high, const bool isOrderByNames)
{
	if (low >= high)
	{
		auto oneElementList = new List;
		oneElementList->pushBack(at(low)->name, at(low)->phoneNumber);
		return oneElementList;
	}
	const int middle = (low + high) / 2;

	auto leftList = merge(low, middle, isOrderByNames);
	auto rightList = merge(middle + 1, high, isOrderByNames);

	auto newSortingList = new List;
	int i = 0;
	int j = 0;
	for (int k = 0; k <= high - low; ++k)
	{
		if (i != -1 && j != -1)
		{
			bool isFirstGreater = compareRecords(*leftList->at(i), *rightList->at(j), isOrderByNames);
			if (isFirstGreater)
			{
				newSortingList->pushBack(rightList->at(j)->name, rightList->at(j)->phoneNumber);
				++j;
				if (j >= rightList->size)
				{
					j = -1;
				}
			}
			else
			{
				newSortingList->pushBack(leftList->at(i)->name, leftList->at(i)->phoneNumber);
				++i;
				if (i >= leftList->size)
				{
					i = -1;
				}
			}
		}
		else
		{
			if (j == -1 && i == -1)
			{
				cout << "Something went wrong" << endl;
				break;
			}
			else
			{
				if (i == -1)
				{
					newSortingList->pushBack(rightList->at(j)->name, rightList->at(j)->phoneNumber);
					++j;
					if (j >= rightList->size)
					{
						j = -1;
					}
				}
				else
				{
					newSortingList->pushBack(leftList->at(i)->name, leftList->at(i)->phoneNumber);
					++i;
					if (i >= leftList->size)
					{
						i = -1;
					}
				}
			}
		}
	}

	delete leftList;
	delete rightList;
	return newSortingList;
}

void List::mergeSort(const bool isOrderByNames)
{
	List *sortedList = merge(0, size - 1, isOrderByNames);
	
	if (size > 1)
	{
		auto current = head;
		for (int i = 0; i <= size - 1; ++i)
		{
			current->name = sortedList->at(i)->name;
			current->phoneNumber = sortedList->at(i)->phoneNumber;
			current = current->next;
		}
	}

	delete sortedList;
}

void List::printList() const
{
	for (auto current = head; current != nullptr; current = current->next)
	{
		cout << "(" << current->name << ":" << current->phoneNumber << ")->";
	}
	cout << "[]" << endl;
}

void List::deleteList()
{
	auto current = head;
	while (head != nullptr)
	{
		current = head->next;
		delete head;
		head = current;
	}
}

bool List::isSorted(const bool isOrderByNames) const
{
	bool isSorted = true;
	for (auto current = head; current != tail; current = current->next)
	{
		if (compareRecords(*current, *(current->next), isOrderByNames))
		{
			isSorted = false;
			break;
		}
	}
	return isSorted;
}