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

int readCheckingFile(string text, vector<vector<int> > &data)
{
	FILE *inputDataFile = fopen(text.c_str(), "r");
	if (!inputDataFile)
	{
		printf("File not found");
		exit(1);
	}

	int linesRead = 0;
	while (!feof(inputDataFile))
	{
		string buffer;
		char *bufferC = new char[100];
		char *readBytes = fgets(bufferC, sizeof(char) * 100, inputDataFile);
		buffer = bufferC;
		delete bufferC;
		if (readBytes == nullptr)
		{
			break;
		}

		vector<int> dataVector;
		int number = 0;
		int counter = 0;
		bool hasOverwritten = false;

		for (auto const &i : buffer)
		{
			if (!isspace(i))
			{
				number = number * 10 + i - '0';
				++counter;
				hasOverwritten = true;
			}
			else
			{
				counter = 0;
				if (hasOverwritten)
				{
					dataVector.push_back(number);
					number = 0;
					hasOverwritten = false;
				}
			}

		}
		data.push_back(dataVector);
	}

	fclose(inputDataFile);

	return linesRead;
}