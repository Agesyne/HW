#include "pch.h"
#include <iostream>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
#include <string>
using namespace std;

int main()
{
	checkFromFile();
	cout << "Enter postfix string: ";
	string calculatingString = "";
	getline(cin, calculatingString);

	const int result = calculatePostFixForm(calculatingString);

	cout << "Result: " << result << endl;

	return 0;
}
