#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

const int debugCounter = 5;
const char* checkMainString[debugCounter] = { "abaabbaaabbb", "baababbabba", "ccunccucnuccucnucn", "ofthisofsueofueosofusegfuo", "21341234" };
const char* checkSubString[debugCounter] = { "a", "ab", "uc", "fo", "4" };
const int checkNumber[debugCounter] = { 6, 3, 4, 0, 2};


void showResult(int number)
{
	printf("Number of occurence: %d", number);
}

int countNumberOfOccurence(const char mainString[], const char subString[])
{
	int counter = 0;
	for (int i = 0; i < strlen(mainString) - strlen(subString) + 1; i++)
	{
		for (int j = 0; j < strlen(subString); j++)
		{
			if (mainString[i + j] != subString[j])
			{
				break;
			}

			if (j == strlen(subString) - 1)
			{
				counter++;
				break;
			}
		}
	}
	return counter;
}

void initString(char mainString[], char subString[])
{
	printf("Enter mainString: ");
	scanf("%s", mainString);
	printf("Enter subString: ");
	scanf("%s", subString);
}


void checkFunction()
{
	for (int i = 0; i < debugCounter; i++)
	{
		const int numberOfOccurence = countNumberOfOccurence(checkMainString[i], checkSubString[i]);
		if (numberOfOccurence != checkNumber[i])
		{
			printf("Some mistakes here\n");
			exit(1);
		}
	}
}

int main()
{
	checkFunction();
	char mainString[255];
	char subString[255];
	initString(mainString, subString);

	int numberOfOccurence = countNumberOfOccurence(mainString, subString);

	showResult(numberOfOccurence);
	return 0;
}