#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
#include "SinglyConnectedList.h"
#include "readFile.h"
using namespace std;


int main()
{
	checkFromFile();
	SinglyConnectedList list;

	vector<string> data;
	readFile("data.txt", data);

	for (auto &i : data[0])
	{
		
		list.push_back(i);
	}
	list.reverse();
	list.print();

	list.deleteList();

	return 0;
}