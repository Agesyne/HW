#include "pch.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

const int debugCounter = 4;
const char* checkString[4] = { "()", ")(", "((())", "" };
const bool checkBool[4] = {true, false, false, true};

void showResult(bool isCorrectString)
{
	printf("This string is ");
	if (isCorrectString)
	{
		printf("CORRECT");
	}
	else
	{
		printf("INCORRECT");
	}
	printf("\n");
}


bool isRightString(const char string[])
{
	int openBracketsCounter = 0, closedBracketsCounter = 0;

	for (int i = 0; i < strlen(string); i++)
	{
		if (string[i] == '(')
		{
			openBracketsCounter++;
		}
		else if (string[i] == ')')
		{
			closedBracketsCounter++;
		}


		if (openBracketsCounter < closedBracketsCounter)
		{
			return false;
		}
	}

	bool isIncorrect = (openBracketsCounter + closedBracketsCounter != strlen(string) || openBracketsCounter != closedBracketsCounter);

	return (isIncorrect) ? false : true;
}


void initString(char bracketString[])
{
	printf("Enter string: ");
	scanf("%s", bracketString);
}


void checkFunction()
{
	for (int i = 0; i < debugCounter; i++)
	{
		const bool isRightBracketsString = isRightString(checkString[i]);
		if (isRightBracketsString != checkBool[i])
		{
			printf("Some mistakes here\n");
			exit(1);
		}
	}
}

int main()
{
	checkFunction();
	char bracketString[255];
	initString(bracketString);

	bool isCorrectString = isRightString(bracketString);

	showResult(isCorrectString);
	return 0;
}