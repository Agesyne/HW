#pragma once
#include <vector>
#include <iostream>
#include <string>

extern struct ArrayField;

class Array
{
private:
	std::vector<ArrayField> thisArray;
public:
	Array();
	~Array();

	void push_back(std::string name, std::string phoneNumber);

	void mergeSort();

	ArrayField operator [](const int index);
};