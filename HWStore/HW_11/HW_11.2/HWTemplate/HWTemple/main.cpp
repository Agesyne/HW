#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
#include "readFile.h"
using namespace std;


int main()
{
	checkFromFile();
	vector<string> sourseStrings;
	readFileByLines("data.txt", sourseStrings);

	string data;
	cout << "Enter data: ";
	cin >> data;

	findFirstEntranceInFile(sourseStrings, data);

	return 0;
}