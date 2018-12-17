#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "readFile.h"
#include "List.h"
using namespace std;

void readFile(string text, vector<string> &data)
{
	ifstream inputDataFile(text, ios::in);
	if (!inputDataFile.is_open())
	{
		cout << "File not found!" << endl;
		return;
	}

	while (!inputDataFile.eof()) {
		string buffer;
		inputDataFile >> buffer;
		if (buffer == "")
		{
			continue;
		}
		data.push_back(buffer);
	}

	inputDataFile.close();
}

void readDataToList(string text, List &list)
{
	ifstream inputDataFile(text, ios::in);
	if (!inputDataFile.is_open())
	{
		cout << "File not found!" << endl;
		return;
	}

	while (!inputDataFile.eof()) {
		string name;
		string phoneNumber;
		inputDataFile >> name;
		inputDataFile >> phoneNumber;
		list.pushBack(name, phoneNumber);
	}

	inputDataFile.close();
}