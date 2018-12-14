#pragma once

extern struct ListElement;

class SinglyConnectedList
{
private:
	ListElement *head = nullptr;
	int size = 0;
public:
	SinglyConnectedList();
	~SinglyConnectedList();

	void push_back(const int);

	void deleteList();

	void reverse();

	void print();

	int getSize();

	ListElement *getHead();

	bool operator== (SinglyConnectedList &);
};

