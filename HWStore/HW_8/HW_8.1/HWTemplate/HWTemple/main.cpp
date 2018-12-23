#include "pch.h"
#include <iostream>
#include <string>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
#include "AVLTree.h"
using namespace std;


int main()
{
	checkFromFile();

	AVLTree tree;
	tree.add("1", "a");
	tree.add("1", "b");
	tree.add("1", "c");
	tree.add("1", "d");
	tree.add("2", "a");
	tree.add("1", "e");
	tree.erase("b");


	return 0;
}