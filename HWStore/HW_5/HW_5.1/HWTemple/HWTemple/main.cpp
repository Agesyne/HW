#include "pch.h"
#include <iostream>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
#include "dataStructures.h"

int main()
{
	setlocale(LC_ALL, "RUS");
	checkFromFile();

	DoubleLinkedList dataBaseList;
	char inputRealTimeData[100]{};
	int commandCode = -1;
	printHelp();
	printf("\"First Program In The World\": \n");

	while (commandCode != 0)
	{
		printf("-> ");
		char *readBytes = fgets(inputRealTimeData, sizeof(char) * 100, stdin);
		if (readBytes == nullptr || (strlen(readBytes) == 1) && readBytes[0] == '\n')
		{
			printf("Ошибка считывания, введите ещё раз\n\n");
			continue;
		}

		processInputCommand(inputRealTimeData, &dataBaseList, &commandCode);
		printf("\n");
	}

	deleteAllList(&dataBaseList);


	printf("Спасибо за использование \"First Program In The World\"\n");
	return 0;
}
