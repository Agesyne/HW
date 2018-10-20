#include "pch.h"
#include <iostream>
#include "dataStructures.h"



void saveDataToFile(const char text[])
{
	FILE *outputFile = fopen(text, "w");

	//����� ���������

	fclose(outputFile);
}

void saveDataBaseToFile(const char text[], BlackRedTree *dataBaseByName)
{
	FILE *outputFile = fopen(text, "w");

	printAllData(dataBaseByName, nullptr, true, outputFile);

	fclose(outputFile);
}