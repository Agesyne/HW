#include "pch.h"
#include "Array.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct ArrayField
{
	string name;
	string phoneNumber;
};

Array::Array()
{
	thisArray.resize(16);
}


Array::~Array()
{
}

void Array::push_back(string name, string phoneNumber)
{
	ArrayField newArrayElement{ name, phoneNumber };
	thisArray.push_back(newArrayElement);
}

void sortByMerging(int low, int high)
{
	
}

void Array::mergeSort(ArrayField arr[], int size)
{
	if (thisArray.size() > 1)
	{
		const int leftSize = thisArray.size() / 2;
		const int rightSize = thisArray.size() - leftSize;
	}

	mergeSort()
}

ArrayField Array::operator [](const int index)
{
	return thisArray[index];
}