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
	//checkFromFile();

	AVLTree tree;
	tree.add("a", "1");
	tree.add("b", "1");
	tree.add("c", "1");
	tree.add("d", "1");
	tree.add("a", "2");
	tree.add("e", "1");
	tree.erase("a");


	return 0;
}