#include "pch.h"
#include <iostream>
#include "readFile.h"
using namespace std;

int readFile(const char text[], string data[100])
{
	FILE *inputDataFile = fopen(text, "r");
	if (!inputDataFile)
	{
		printf("File not found");
		exit(1);
	}

	int linesRead = 0;

	while (!feof(inputDataFile))
	{
		char *buffer = new char[100];
		char *readBytes = fgets(buffer, sizeof(char) * 100, inputDataFile);
		if (readBytes == nullptr)
		{
			delete[] buffer;
			break;
		}
		data[linesRead++] = buffer;
	}

	fclose(inputDataFile);
	return linesRead;
}