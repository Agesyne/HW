#include "pch.h"
#include <iostream>
#include "main.h"


void printBitNumber(int bitNumber[], const char text[] = "")
{
	const int length = 32;
	printf("%s", text);
	for (int i = 0; i < length; i++)
	{
		printf("%d", bitNumber[i]);
	}
	printf("\n");
}

void decToTwosComplement(const int number, int *bitNumber[])
{
	const int maxNumberBitLength = 32;
	*bitNumber = new int[maxNumberBitLength];

	int bitMask = 1;
	for (int i = maxNumberBitLength - 1; i >= 0; i--)
	{
		(*bitNumber)[i] = (number & bitMask) ? 1 : 0;
		bitMask <<= 1;
	}
}

void addBitNumbers(const int bitNumber1[], const int bitNumber2[], int *addResult[])
{
	const int lengthNumber = 32;
	*addResult = new int[lengthNumber];
	
	int crossBit = 0;
	for (int i = lengthNumber - 1; i >= 0; i--)
	{
		(*addResult)[i] = bitNumber1[i] + bitNumber2[i] + crossBit;
		crossBit = 0;
		if ((*addResult)[i] > 1)
		{
			(*addResult)[i] %= 2;
			crossBit = 1;
		}
	}
}

int twosComplementToDec(int addResult[])
{
	setlocale(LC_ALL, "RUS");
	const int addResultLength = 32;
	int resultNumber = 0;
	int sign = 1;

	//если число меньше 0
	if (addResult[0] == 1)
	{
		sign = -1;
		int crossBit = 0;
		
		for (int j = addResultLength - 1; j > 0; --j)
		{
			addResult[j] = addResult[j] + crossBit + 1;
			crossBit = addResult[j] / 2;
			addResult[j] %= 2;
		}

		for (int i = 0; i < addResultLength; i++)
		{
			addResult[i] = 1 - addResult[i];
		}
	}

	int bitMask = 1;
	for (int i = addResultLength - 1; i >= 0; i--)
	{
		resultNumber += addResult[i] * bitMask;
		bitMask <<= 1;
	}
	resultNumber *= sign;

	return resultNumber;
}