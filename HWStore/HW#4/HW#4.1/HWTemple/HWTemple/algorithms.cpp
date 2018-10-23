#include "pch.h"
#include <iostream>
#include "main.h"

int pow2(const int degree)
{
	int number = 1;
	for (int i = 0; i < degree; i++)
	{
		number *= 2;
	}
	return number;
}

bool checkIfMin(int *addResult, const int addResultLength)
{
	bool isAllZeros = true;
	for (int i = 1; i < addResultLength; i++)
	{
		if (addResult[i])
		{
			return false;
		}
	}
	return true;
}

void printBitNumber(int *bitNumber, const int length, const char text[] = "")
{
	printf("%s", text);
	for (int i = 0; i < length; i++)
	{
		printf("%d", bitNumber[i]);
	}
	printf("\n");
}

int calculateMaxLength(const int number1, const int number2)
{
	int number = max(number1, number2);
	int counter = 0;

	while (number > 0)
	{
		counter++;
		number /= 2;
	}
	return counter + 1; //+ бит знака
}

void decToTwosComplement(const int number, int bitNumber[], const int numberLength)
{
	int bitMask = 1;
	for (int i = numberLength - 1; i >= 0; i--)
	{
		bitNumber[i] = (number & bitMask) ? 1 : 0;
		bitMask <<= 1;
	}
}

int *addBitNumbers(const int bitNumber1[], const int bitNumber2[], const int lengthNumber)
{
	int *resultBitNumber = new int[lengthNumber];
	
	int crossBit = 0;

	for (int i = lengthNumber - 1; i >= 0; i--)
	{
		resultBitNumber[i] = bitNumber1[i] + bitNumber2[i] + crossBit;
		crossBit = 0;
		if (resultBitNumber[i] > 1)
		{
			resultBitNumber[i] %= 2;
			crossBit = 1;
		}
	}

	return resultBitNumber;
}

int twosComplementToDec(int addResult[], const int addResultLength)
{
	int resultNumber = 0;
	int bitMask = 1;
	int sign = 1;

	//перевод в прямой код, если число меньше 0
	if (addResult[0] == 1)
	{
		if (checkIfMin(addResult, addResultLength))
		{
			return -pow2(addResultLength - 1);
		}
		sign = -1;
		int j = addResultLength - 1;
		
		for (int i = 0; i < addResultLength; i++)
		{
			addResult[i] = 1 - addResult[i];
		}
		addResult[j]++;
		while (addResult[j] > 1 && j > 0)
		{
			addResult[j] = addResult[j] % 2;
			j--;
			if (j != 0)
			{
				addResult[j]++;
			}
		}
	}

	for (int i = addResultLength - 1; i >= 0; i--)
	{
		resultNumber += addResult[i] * bitMask;
		bitMask <<= 1;
	}

	
	resultNumber *= sign;
	return resultNumber;
}