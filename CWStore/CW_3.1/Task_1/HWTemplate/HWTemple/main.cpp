#include "pch.h"
#include <string>
#include <vector>
#include <algorithm>
#include "check.h"
#include "readFile.h"
#include "saveData.h"
using namespace std;


int main()
{
	//checkFromFile();
	
	vector<string> data;
	readFile("data.txt", data);

	sort(data.begin(), data.end());
	auto lastExpectedResult = unique(data.begin(), data.end());
	data.erase(lastExpectedResult, data.end());

	saveDataToFile("result.txt", data);

	return 0;
}