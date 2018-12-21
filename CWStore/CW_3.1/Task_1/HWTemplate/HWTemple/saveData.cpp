#include "pch.h"
#include <string>
#include <vector>
#include <fstream>
using namespace std;

void saveDataToFile(const string &text, vector<string> &data)
{
	ofstream outputDataFile(text, ios::out);

	for (const auto &i : data)
	{
		outputDataFile << i << endl;
	}

	outputDataFile.close();
}
