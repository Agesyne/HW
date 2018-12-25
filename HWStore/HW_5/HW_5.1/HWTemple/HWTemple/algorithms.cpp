#include "pch.h"
#include <iostream>
#include <string.h>
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

void printInsertingData(const int data)
{
	printf("������� %d ��������\n", data);
}

void printDeletingData(const int data, const bool hasFound)
{
	if (hasFound)
	{
		printf("������� %d �����\n", data);
	}
	else
	{
		printf("�������� %d ��� � ������\n", data);
	}
}

void printHelp()
{
	printf("������ �������:\n");
	printf("   ->���������\n");
	printf("      |--------------------------------------------------------------|\n");
	printf("\t ��������: ����� �����\n");
	printf("\t �������: \"0\" ��� \"\" - ������ �������, \"1\" - ��������\n");
	printf("      |--------------------------------------------------------------|\n");
	printf("   ->����� �� ���������:\t\"0\"\n");
	printf("   ->�������� ��������: \t\"1 ��������\"\n");
	printf("   ->������� ��������:  \t\"2 ��������\"\n");
	printf("   ->����������� ������:\t\"3 �������\"\n");
	printf("\n");
}

void processInputCommand(const char buffer[], DoubleLinkedList *list, int *commandNumber)
{
	int commandOffset = 0;
	sscanf(buffer, "%d%n", commandNumber, &commandOffset);

	if (*commandNumber < 0 || *commandNumber > 3)
	{
		printf("�������� ����� �������: %d\n", *commandNumber);
		printHelp();
		return;
	}

	int data = 0;
	switch (*commandNumber)
	{
		case 0:
			break;

		case 1:
			sscanf(buffer + commandOffset, " %d", &data);
			insertElementToList(list, data, &printInsertingData);
			break;

		case 2:
			sscanf(buffer + commandOffset, " %d", &data);
			deleteElmentFromList(list, data, &printDeletingData);
			break;

		case 3:
			sscanf(buffer + commandOffset, " %d", &data);
			if (data == 0)
			{
				printAllData(list);
			}
			else if (data == 1)
			{
				printAllData(list, false);
			}
			else
			{
				printf("�������� �������� ��������: (%s)\n", data);
				printHelp();
				break;
			}
			break;

		default:
			printf("�������� ����� ��������: %s\n", *commandNumber);
			printHelp();
			break;
	}
}