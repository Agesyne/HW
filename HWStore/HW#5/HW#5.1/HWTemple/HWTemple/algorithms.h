#pragma once
#include "dataStructures.h"

int max(const int number1, const int number2);

void swap(int *a, int *b);

void printHelp();

void processInputCommand(const char buffer[], DoubleLinkedList *list, int *commandNumber);
