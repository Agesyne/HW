#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "readFile.h"
using namespace std;

int readFile(string text, vector<string> &data)
{
	ifstream inputDataFile(text, ios::in);
	if (!inputDataFile.is_open())
	{
		cout << "File not found!" << endl;
		return 1;
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