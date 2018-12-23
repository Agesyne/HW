#include "pch.h"
#include <iostream>
#include <string>
#include "BinarySearchTree.h"
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
using namespace std;


int main()
{
	checkFromFile();
	BinarySearchTree tree;

	string commandArguments;
	int commandCode = -1;
	printHelp();
	printf("Phone Number Database: \n");
	while (commandCode != 0)
	{
		cout << "-> ";
		
		cin >> commandCode;
		
		processInputCommand(tree, commandCode);
		cout << endl;
	}

	tree.deleteAll();

	return 0;
}