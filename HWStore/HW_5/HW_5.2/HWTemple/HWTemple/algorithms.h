#pragma once
#include "dataStructures.h"

int max(const int number1, const int number2);

void swap(int *a, int *b);

void killAllMenExceptN(CyclicBiconnectedList *deadmenList, const int period, const int howManyStayAlive);

void processDataString(const char buffer[], CyclicBiconnectedList *enteringList, int *result, int *period);

