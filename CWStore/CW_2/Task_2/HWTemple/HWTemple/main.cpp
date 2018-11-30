#include "pch.h"
#include <iostream>
#include <string>
#include "check.h"
#include "initialization.h"
#include "readFile.h"
#include "algorithms.h"
#include <vector>
#include <string>
#include "DoubleLinkedList.h"
using namespace std;


int main()
{
	checkFromFile();
	vector<string> inputData;
	readFile("data.txt", inputData);

	DoubleLinkedList list;

	for (auto const &i : inputData)
	{
		int data = 0;
		for (auto const &j : i)
		{
			data = data * 10 + j - '0';
		}
		list.push_back(data);
	}

	cout << "This list is " <<((list.isSymmetric()) ? "Symmetric" : "Not Symmetric") << endl;

	list.deleteAllList();

	return 0;
}