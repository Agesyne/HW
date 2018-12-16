#include "pch.h"
#include <iostream>
#include <string.h>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
#include "dataStructures.h"
#include "readFile.h"


int main()
{
	setlocale(LC_ALL, "RUS");
	checkFromFile();

	char *data[100] = {};
	const int linesRead = readFile("data.txt", data);
	BlackRedTree dataBaseByName;
	BlackRedTree dataBaseByNumber;

	for (int linesCounter = 0; linesCounter < linesRead; linesCounter++)
	{
		char *buffer = data[linesCounter];
		processInputString(buffer, &dataBaseByName, &dataBaseByNumber);
		delete[] buffer;
	}

	char inputRealTimeData[100]{};
	int commandCode = -1;
	printHelp();
	printf("Phone Number Database: \n");
	while (commandCode != 0)
	{
		printf("-> ");
		
		char *readBytes = fgets(inputRealTimeData, sizeof(char) * 100, stdin);
		if (readBytes == nullptr)
		{
			printf("Ошибка читывания, введите ещё раз\n");
			continue;
		}
		
		processInputCommand(inputRealTimeData, &dataBaseByName, &dataBaseByNumber, &commandCode);
		printf("\n");
	}

	printf("Спасибо за использование \"Phone Number HandBook\"\n");
	deletetAllData(&dataBaseByName);
	deletetAllData(&dataBaseByNumber);
	delete leaf;

	return 0;
}
