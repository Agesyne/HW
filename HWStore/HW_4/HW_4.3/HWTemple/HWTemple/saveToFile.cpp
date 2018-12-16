#include "pch.h"
#include <iostream>
#include "dataStructures.h"



void saveDataToFile(const char text[])
{
	FILE *outputFile = fopen(text, "w");

	//здесь сохраняем

	fclose(outputFile);
}

void saveDataBaseToFile(const char text[], BlackRedTree *dataBaseByName)
{
	FILE *outputFile = fopen(text, "w");

	if (outputFile != nullptr)
	{
		printAllData(dataBaseByName, nullptr, outputFile);
	}
	else
	{
		printf("Не удалось создать файл с именем %s\n", text);
		return;
	}

	fclose(outputFile);
}