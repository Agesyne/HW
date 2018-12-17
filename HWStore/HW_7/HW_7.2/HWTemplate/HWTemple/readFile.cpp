#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "readFile.h"
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
		getline(inputDataFile, buffer);
		if (buffer == "")
		{
			continue;
		}
		data.push_back(buffer);
	}

	inputDataFile.close();
}