#include "pch.h"
#include <iostream>
#include "algorithms.h"
#include "readFile.h"
#include "check.h"


void autoGeneratedCheck()
{
	srand(0);
	const int debugNumber = 10;

	for (int i = 0; i < debugNumber; i++)
	{
		if (0)
		{
			exit(1);
		}
	}
}

void checkFromFile()
{
	string data[100] = {};
	const int linesRead = readFile("checkData.txt", data);

	string results[100] = {};
	const int linesResultRead = readFile("resultData.txt", results);

	for (int linesCounter = 0; linesCounter < linesRead; ++linesCounter)
	{
		const bool isCorrectString = isCorrectBracketsString(data[linesCounter]);

		if (isCorrectString != (bool)(results[linesCounter][0] - '0'))
		{
			cout << "�� ��������" << endl;
			exit(1);
		}
	}
}