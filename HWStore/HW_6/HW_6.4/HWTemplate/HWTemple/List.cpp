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

struct ArrayElement
{
	string name;
	string phoneNumber;
};

List::List()
{
}


List::~List()
{
	deleteList();
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
bool compareRecords(const ArrayElement &record1, const ArrayElement &record2, const bool isOrderByNames)
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

void merge(ArrayElement sortingArray[], const int low, const int high, const bool isOrderByNames)
{
	if (low >= high)
	{
		return;
	}
	const int middle = (low + high) / 2;

	merge(sortingArray, low, middle, isOrderByNames);
	merge(sortingArray, middle + 1, high, isOrderByNames);

	auto extraArray = new ArrayElement[high - low + 1];
	int i = low;
	int j = middle + 1;
	for (int k = 0; k <= high - low; ++k)
	{
		if (i != -1 && j != -1)
		{
			bool isFirstGreater = compareRecords(sortingArray[i], sortingArray[j], isOrderByNames);
			if (isFirstGreater)
			{
				extraArray[k] = sortingArray[j];
				++j;
				if (j > high)
				{
					j = -1;
				}
			}
			else
			{
				extraArray[k] = sortingArray[i];
				++i;
				if (i > middle)
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
					extraArray[k] = sortingArray[j];
					++j;
					if (j > high)
					{
						j = -1;
					}
				}
				else
				{
					extraArray[k] = sortingArray[i];
					++i;
					if (i > middle)
					{
						i = -1;
					}
				}
			}
		}
	}

	for (int k = low; k <= high; ++k)
	{
		sortingArray[k] = extraArray[k - low];
	}
	delete[] extraArray;
}

void List::mergeSort(const bool isOrderByNames)
{
	auto sortingArray = new ArrayElement[size];
	int low = 0;
	int high = size - 1;

	int counter = 0;
	for (auto current = head; current != nullptr; current = current->next)
	{
		sortingArray[counter] = ArrayElement{ current->name, current->phoneNumber };
		++counter;
	}

	merge(sortingArray, low, high, isOrderByNames);

	auto current = head;
	for (int i = low; i <= high; ++i)
	{
		current->name = sortingArray[i].name;
		current->phoneNumber = sortingArray[i].phoneNumber;
		current = current->next;
	}

	delete[] sortingArray;
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
		ArrayElement record1{current->name, current->phoneNumber};
		ArrayElement record2{current->next->name, current->next->phoneNumber };
		if (compareRecords(record1, record2, isOrderByNames))
		{
			isSorted = false;
			break;
		}
	}
	return isSorted;
}