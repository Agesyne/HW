#include "pch.h"
#include "algorithms.h"
#include <vector>
#include <string>
#include <fstream>
#include <iostream>
using namespace std;

vector<int> *prefixFunction(const string &data)
{
	auto prefixData = new vector<int>(data.length());

	for (int i = 1; i < data.length(); ++i)
	{
		int j = (*prefixData)[i - 1];
		while ((j > 0) && (data[i] != data[j]))
		{
			j = (*prefixData)[j - 1];
		}

		if (data[i] == data[j])
		{
			++j;
		}
		(*prefixData)[i] = j;
	}

	return prefixData;
}

int findFirstEntrance(const string &sourse, const string &data, vector<int> *prefixData)
{
	int j = 0;
	for (int i = 0; i < sourse.length(); ++i)
	{
		while ((j > 0) && (sourse[i] != data[j]))
		{
			j = (*prefixData)[j - 1];
		}

		if (sourse[i] == data[j])
		{
			++j;
		}

		if (j == data.length())
		{
			return i + 2 - data.length();
		}
	}

	return -1;
}

void findFirstEntranceInFile(const vector<string> &sourseStrings, const string &data, const string &outputFileName)
{
	auto prefixData = prefixFunction(data);

	if (outputFileName != "")
	{
		ofstream outputFileStream(outputFileName, ios::trunc);
		outputFileStream.close();
	}

	for (int i = 0; i < sourseStrings.size(); ++i)
	{
		const int answer = findFirstEntrance(sourseStrings[i], data, prefixData);
		if (answer != -1)
		{
			if (outputFileName != "")
			{
				ofstream outputFileStream(outputFileName, ios::app);

				outputFileStream << i + 1 << "." << answer << endl;

				outputFileStream.close();
				break;
			}
			else
			{
				cout << i + 1 << "." << answer << endl;
			}
			break;
		}
	}

	delete prefixData;
}