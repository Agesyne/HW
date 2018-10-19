#include "pch.h"
#include <iostream>

int readFile(const char text[], char *data[100])
{
	FILE *inputDataFile = fopen(text, "r");
	if (!inputDataFile)
	{
		printf("File not fount");
		exit(1);
	}

	int linesRead = 0;

	while (!feof(inputDataFile))
	{
		char *buffer = new char[100];
		char *readBytes = fgets(buffer, sizeof(char) * 100, inputDataFile);
		if (readBytes == nullptr)
		{
			break;
		}
		data[linesRead++] = buffer;
	}

	fclose(inputDataFile);
	return linesRead;
}