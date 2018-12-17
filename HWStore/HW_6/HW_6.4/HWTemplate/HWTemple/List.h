#pragma once
#include <iostream>
#include <string>

extern struct ListElement;

class List
{
private:
	ListElement *head = nullptr;
	ListElement *tail = nullptr;
	int size = 0;
public:
	List();
	~List();

	void pushBack(const std::string &name, const std::string &phoneNumber);

	void mergeSort(const bool isOrderByNames = true);

	void printList() const;

	void deleteList();

	bool isSorted(const bool isOrderByNames = true) const;
};

