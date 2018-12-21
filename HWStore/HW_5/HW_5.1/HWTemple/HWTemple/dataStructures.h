#pragma once

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


bool isEmpty(DoubleLinkedList *list);

void insertElementToList(DoubleLinkedList *list, const int data, void(*printData)(const int data) = nullptr);

void deleteElmentFromList(DoubleLinkedList *list, const int data, void(*printData)(const int data, bool hasFound) = nullptr);

void printAllData(DoubleLinkedList *list, bool isStraightOrder = true, FILE *outputFile = nullptr);

void deleteAllList(DoubleLinkedList *list);
