#include "pch.h"
#include <iostream>
#include "main.h"


int partition(int sortingArray[], const int low, const int high)
{
	const int pivotNumber = (sortingArray[low] + sortingArray[(low + high) / 2] + sortingArray[high]) / 3;
	int i = low;
	int j = high;

	while (i <= j)
	{
		while (sortingArray[i] < pivotNumber)
		{
			i++;
		}

		while (pivotNumber < sortingArray[j])
		{
			j--;
		}

		if (i >= j)
		{
			break;
		}

		swap(&sortingArray[i++], &sortingArray[j--]);
	}
	return j;
}

void quickSort(int sortingArray[], const int low, const int high)
{
	if (low < high)
	{
		const int middle = partition(sortingArray, low, high);
		quickSort(sortingArray, low, middle);
		quickSort(sortingArray, middle + 1, high);
	}
}


int findMaxFrequencyNumber(int enteredArray[], const int arraySize)
{
	int maxFrequencyNumber = -1;
	int maxFrequency = -1;
	int i = 0;
	while (i < arraySize)
	{
		int number = enteredArray[i];
		int counter = 0;

		while (enteredArray[i] == number)
		{
			counter++;
			i++;
		}

		if (maxFrequency < counter)
		{
			maxFrequency = counter;
			maxFrequencyNumber = number;
		}
	}
	return maxFrequencyNumber;
}

void processInputString(const char buffer[], int *enteredArray[], int *arraySize, int *result)
{
	//������������� ������

	bool isArrayBegun = false;			//��������� �� ��� ������
	int arrayIndex = 0;

	bool isNumberNext = false;			//���� ������ ����� - ��������� ���
	int numberCounter = 0;				//����� ���������� �����


	for (int charCounter = 0; buffer[charCounter] != '\n' && buffer[charCounter] != '\0'; charCounter++)
	{
		if (buffer[charCounter] == '=') //������� '='
		{
			isNumberNext = true;
			numberCounter++;
			charCounter++;
			continue;
		}

		if (isArrayBegun && buffer[charCounter] == ' ') //��������� ����� �������
		{
			isNumberNext = true;
			continue;
		}

		if (isNumberNext) //��������� �����
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

			if (!isArrayBegun) //������ ����� � ������ �����
			{
				switch (numberCounter)
				{
				case 1:
					*arraySize = numberFromString;
					*enteredArray = new int[*arraySize];
					break;
				case 2:
					*result = numberFromString;
					break;
				}
			}
			else
			{
				(*enteredArray)[arrayIndex++] = numberFromString;
			}

			charCounter += digitLength - 1;
			isNumberNext = false;
			continue;
		}

		if (buffer[charCounter] == ':') //������� ������
		{
			isArrayBegun = true;
		}

	}
}