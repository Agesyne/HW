#include "pch.h"
#include "algorithms.h"
#include <iostream>
using namespace std;

string getHash(const string &data)
{
	string key;

	if (data.length() == 0)
	{
		key = "/0";
		return key;
	}

	if (data.length() == 1)
	{
		key = data[0] + '\0';
		return key;
	}

	key = data[0] + data[1];
	return key;
}
