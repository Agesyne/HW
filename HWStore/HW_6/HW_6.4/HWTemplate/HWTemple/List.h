#pragma once
#include <iostream>
#include <string>

struct ListElement;

class List
{
private:
	ListElement *head = nullptr;
	ListElement *tail = nullptr;
	int size = 0;
public:
	List();
	~List();

	ListElement *at(const int number) const;

	void pushBack(const std::string &name, const std::string &phoneNumber);

	void mergeSort(const bool isOrderByNames = true);

	List *merge(const int low, const int high, const bool isOrderByNames);

	void printList() const;

	void deleteList();

	bool isSorted(const bool isOrderByNames = true) const;
};

