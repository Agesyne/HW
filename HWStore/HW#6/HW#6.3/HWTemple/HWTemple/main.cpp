#include "pch.h"
#include <iostream>
#include <string>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
using namespace std;


int main()
{
	checkFromFile();
	string infixInputString;
	cout << "Enter infix string: ";
	getline(cin, infixInputString);

	string postfix = translateToPostfix(infixInputString);

	cout << "Postfix form: " << postfix << endl;

	return 0;
}
