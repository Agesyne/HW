#include "pch.h"
#include <iostream>
#include <string>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
#include "ExpressionTree.h"
using namespace std;


int main()
{
	checkFromFile();
	ExpressionTree tree;

	string expression = "(* (+ 1 1) 2)";
	cout << "Enter expression: ";
	getline(cin, expression);

	tree.readExpressionTree(expression);
	cout << "Result: " << tree.countExpression() << endl;

	tree.deleteAll();

	return 0;
}