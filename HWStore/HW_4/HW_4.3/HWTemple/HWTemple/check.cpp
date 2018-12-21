#include "pch.h"
#include <iostream>
#include "algorithms.h"
#include "readFile.h"


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

void deleteTMPData(const int linesRead, char *data[100])
{
	for (int i = 0; i < linesRead; ++i)
	{
		delete data[i];
	}
}

void checkFromFile()
{

	char *checkData[100] = {};
	const int checkDatalLinesRead = readFile("checkData.txt", checkData);

	char *resultData[100] = {};
	const int resultDatalLinesRead = readFile("resultData.txt", resultData);

	for (int linesCounter = 0; linesCounter < checkDatalLinesRead; linesCounter++)
	{
		// ���� � ����������
		BlackRedTree treeByNames;
		BlackRedTree treeByNumbers;

		char *data[100] = {};
		const int commandslinesRead = readFile(checkData[linesCounter], data);

		for (int i = 0; i < commandslinesRead; ++i)
		{
			int commandNumber = 0;
			processInputCommand(data[i], &treeByNames, &treeByNumbers, &commandNumber);
		}

		FILE *outputDataFile = fopen("toCheckDataByNames.txt", "w");
		printAllData(&treeByNames, nullptr, outputDataFile);
		fclose(outputDataFile);

		outputDataFile = fopen("toCheckDataByNumbers.txt", "w");
		printAllData(&treeByNumbers, nullptr, outputDataFile);
		fclose(outputDataFile);

		// �������� �� ������

		char *resultByNames[100] = {};
		const int resultByNamesLinesRead = readFile(resultData[linesCounter * 2], resultByNames);

		char *answerByNames[100] = {};
		const int answerByNamesLinesRead = readFile("toCheckDataByNames.txt", answerByNames);
		
		bool isSameByNames = true;
		for (int i = 0; i < answerByNamesLinesRead; ++i)
		{
			if (strcmp(answerByNames[i], resultByNames[i]) != 0)
			{
				isSameByNames = false;
				break;
			}
		}

		// �������� �� �������

		char *answerByNumbers[100] = {};
		const int answerByNumbersLinesRead = readFile("toCheckDataByNumbers.txt", answerByNumbers);

		char *resultByNumbers[100] = {};
		const int resultByNumbersLinesRead = readFile(resultData[linesCounter * 2 + 1], resultByNumbers);

		bool isSameByNumbers = true;
		for (int i = 0; i < answerByNumbersLinesRead; ++i)
		{
			if (strcmp(answerByNumbers[i], resultByNumbers[i]) != 0)
			{
				isSameByNumbers = false;
				break;
			}
		}

		// ������ ������

		if (!(isSameByNames && isSameByNumbers))
		{
			printf("Mistakes\n");
			for (int i = linesCounter; i < commandslinesRead; ++i)
			{
				deleteTMPData(commandslinesRead, data);
				deleteTMPData(resultByNamesLinesRead, resultByNames);
				deleteTMPData(answerByNamesLinesRead, answerByNames);
				deleteTMPData(resultByNumbersLinesRead, resultByNumbers);
				deleteTMPData(answerByNumbersLinesRead, answerByNumbers);
				deleteAllData(&treeByNames);
				deleteAllData(&treeByNumbers);
			}
			exit(1);
		}

		// �������� ������������� ������
		deleteTMPData(commandslinesRead, data);
		deleteTMPData(resultByNamesLinesRead, resultByNames);
		deleteTMPData(answerByNamesLinesRead, answerByNames);
		deleteTMPData(resultByNumbersLinesRead, resultByNumbers);
		deleteTMPData(answerByNumbersLinesRead, answerByNumbers);
		deleteAllData(&treeByNames);
		deleteAllData(&treeByNumbers);
	}

	deleteTMPData(checkDatalLinesRead, checkData);
	deleteTMPData(resultDatalLinesRead, resultData);
}