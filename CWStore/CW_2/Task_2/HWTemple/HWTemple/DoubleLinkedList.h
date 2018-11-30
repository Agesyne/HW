#pragma once
extern struct ListElement;

class DoubleLinkedList
{
private:
	int size;
	ListElement *head;
	ListElement *tail;
public:
	DoubleLinkedList();
	~DoubleLinkedList();

	bool isEmpty();

	void insertElementToList(const int data);

	void push_back(const int data);

	void deleteElementFromList(const int data);

	void printAllData(bool isStraightOrder = true);

	void deleteAllList();

	ListElement *getHead();

	ListElement *getTail();

	bool isSymmetric();
};

