#include "pch.h"
#include "algorithms.h"
#include <iostream>
using namespace std;


void printArray(const int printingArray[], const int low, const int high)
{
	for (int i = low; i <= high; i++)
	{
		printf("%d ", printingArray[i]);
	}
	printf("\n");
}