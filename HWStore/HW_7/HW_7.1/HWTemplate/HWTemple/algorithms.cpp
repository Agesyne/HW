#include "pch.h"
#include "algorithms.h"
#include <iostream>
#include <string>
using namespace std;

void printHelp()
{
	cout << "How to use it:" << endl;
	cout << "data: (integer); order: (0 - stright / 1 - reverse)" << endl;
	cout << "\t0 -> end session" << endl;
	cout << "\t1 (data) -> add data to tree" << endl;
	cout << "\t2 (data) -> delete data from tree" << endl;
	cout << "\t3 (data) -> check if data in tree" << endl;
	cout << "\t4 (order) -> print all data in the order" << endl;
	cout << endl;
}

void processInputCommand(BinarySearchTree &tree, int commandNumber)
{
	if (commandNumber < 0 || commandNumber > 4)
	{
		cout << "Wrong command number: (" << commandNumber << ")" << endl;
		printHelp();
		return;
	}

	switch (commandNumber)
	{
	case 0:
		break;

	case 1:
		{
			int data = 0;
			cin >> data;

			if (tree.add(data))
			{
				cout << "Data (" << data << ") added" << endl;
			}
			else
			{
				cout << "Data (" << data << ") is already in tree" << endl;
			}
		}
		break;

	case 2:
		{
			int data = 0;
			cin >> data;

			if (tree.erase(data))
			{
				cout << "Data (" << data << ") deleted" << endl;
			}
			else
			{
				cout << "Data (" << data << ") is already off tree" << endl;
			}
		}
		break;

	case 3:
		{
			int data = 0;
			cin >> data;

			if (tree.find(data))
			{
				cout << "Data (" << data << ") is IN tree" << endl;
			}
			else
			{
				cout << "Data (" << data << ") is OFF tree" << endl;
			}
		}
		break;

	case 4:
		{
			int order = 0;
			cin >> order;

			bool isStraightOrder = (order == 0);
			tree.printAll(isStraightOrder);
		}
		break;

	default:
		cout << "Wrong command number: (" << commandNumber << ")" << endl;
		printHelp();
		break;
	}
}