#include "pch.h"
#include <iostream>
#include "dataStructures.h"


void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int max(const int number1, const int number2)
{
	if (number2 < number1)
	{
		return number1;
	}
	else
	{
		return number2;
	}
}

void killAllMenExceptN(CyclicBiconnectedList *deadmenList, const int period, const int howManyStayAlive)
{
	int number = 0;
	while (getListSize(deadmenList) > howManyStayAlive)
	{
		number += period;
		number %= getListSize(deadmenList);
		deleteElementFromList(deadmenList, number);
	}
}

void processDataString(const char buffer[], CyclicBiconnectedList *enteringList, int *result, int *period)
{
	bool isNumberNext = false;	
	int numberCounter = 0;	
	int deadmenNumber = 0;


	for (int charCounter = 0; buffer[charCounter] != '\n' && buffer[charCounter] != '\0'; charCounter++)
	{
		if (buffer[charCounter] == '=')
		{
			isNumberNext = true;
			numberCounter++;
			charCounter++;
			continue;
		}

		if (isNumberNext)
		{
			int digitLength = 0;
			for (int i = 0;;)
			{
				if (isdigit(buffer[charCounter + i]))
				{
					i++;
				}
				else
				{
					digitLength = i;
					break;
				}
			}

			int numberFromString = 0;
			for (int i = 0; i < digitLength; i++)
			{
				numberFromString = numberFromString * 10 + (buffer[charCounter + i] - '0');
			}

			switch (numberCounter)
			{
				case 1:
					deadmenNumber = numberFromString;

					for (int i = 1; i <= deadmenNumber; i++)
					{
						addElementToList(enteringList, getListSize(enteringList), i);
					}

					break;
				case 2:
					*period = numberFromString;
					break;
				case 3:
					*result = numberFromString;
					break;
			}

			charCounter += digitLength - 1;
			isNumberNext = false;
			continue;
		}
	}
}