#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
using namespace std;


int main()
{
	//checkFromFile();
	
	vector<int> data;
	cout << "Enter numbers: ";
	int number = -1;
	while (number != 0)
	{
		cin >> number;
		if (number == 0)
		{
			break;
		}
		data.push_back(number);
	}

	sort(data.begin(), data.end());

	int prevNumber = 0;
	int counter = 0;
	for (auto &i : data)
	{
		if (i != prevNumber && prevNumber != 0)
		{
			cout << prevNumber << "(" << counter << ") ";
			counter = 0;
		}
		prevNumber = i;
		counter++;
	}

	return 0;
}