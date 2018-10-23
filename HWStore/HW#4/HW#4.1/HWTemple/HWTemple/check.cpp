#include "pch.h"
#include <iostream>
#include "main.h"
#include "algorithms.h"
#include "readFile.h"


void autoGeneratedCheck()
{
	srand(0);
	const int debugNumber = 100;
	const int maxRandomNumberBitLength = 8;
	const int maxRandomNumber = pow2(maxRandomNumberBitLength - 1);

	for (int i = 0; i < debugNumber; i++)
	{
		bool isOffBound = false;
		int number1 = rand() % maxRandomNumber - rand() % maxRandomNumber;
		int number2 = rand() % maxRandomNumber - rand() % maxRandomNumber;

		int *bitNumber1 = new int[maxRandomNumberBitLength];
		int *bitNumber2 = new int[maxRandomNumberBitLength];

		decToTwosComplement(number1, bitNumber1, maxRandomNumberBitLength);
		decToTwosComplement(number2, bitNumber2, maxRandomNumberBitLength);

		int *addResult = addBitNumbers(bitNumber1, bitNumber2, maxRandomNumberBitLength);

		const int bitSum = twosComplementToDec(addResult, maxRandomNumberBitLength);

		
		const int numberSum = number1 + number2;
		if (numberSum > maxRandomNumber - 1 || numberSum < -maxRandomNumber)
		{
			isOffBound = true;
		}

		//������������ �� �����������
		if (bitSum != (numberSum % maxRandomNumber) && !isOffBound)
		{
			printf("���-�� ������");
			delete[] bitNumber1;
			delete[] bitNumber2;
			delete[] addResult;
			exit(1);
		}

		delete[] bitNumber1;
		delete[] bitNumber2;
		delete[] addResult;
	}
}

void checkFromFile()
{
	char *data[100] = {};
	const int linesRead = readFile("checkData.txt", data);

	for (int linesCounter = 0; linesCounter < linesRead; linesCounter++)
	{
		if (0)
		{
			exit(1);
		}
	}
}