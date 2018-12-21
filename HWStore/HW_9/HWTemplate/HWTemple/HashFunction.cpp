#include "pch.h"
#include "HashFunction.h"
#include <iostream>
#include <string>
using namespace std;

int hashFunction(string sourse)
{
	int key = 0;
	int multiplier = 1;

	for (auto const &i : sourse)
	{
		key += i * multiplier;
		multiplier *= 3;
	}

	return key;
}