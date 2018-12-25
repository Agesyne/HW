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
	printf("Элемент %d добавлен\n", data);
}

void printDeletingData(const int data, const bool hasFound)
{
	if (hasFound)
	{
		printf("Элемент %d удалён\n", data);
	}
	else
	{
		printf("Элемента %d нет в списке\n", data);
	}
}

void printHelp()
{
	printf("Список комманд:\n");
	printf("   ->Пояснение\n");
	printf("      |--------------------------------------------------------------|\n");
	printf("\t Значение: целое число\n");
	printf("\t Порядок: \"0\" или \"\" - прямой порядок, \"1\" - обратный\n");
	printf("      |--------------------------------------------------------------|\n");
	printf("   ->Выйти из программы:\t\"0\"\n");
	printf("   ->Добавить значение: \t\"1 Значение\"\n");
	printf("   ->Удалить значение:  \t\"2 Значение\"\n");
	printf("   ->Распечатать список:\t\"3 Порядок\"\n");
	printf("\n");
}

void processInputCommand(const char buffer[], DoubleLinkedList *list, int *commandNumber)
{
	int commandOffset = 0;
	sscanf(buffer, "%d%n", commandNumber, &commandOffset);

	if (*commandNumber < 0 || *commandNumber > 3)
	{
		printf("Невреный номер команды: %d\n", *commandNumber);
		printHelp();
		return;
	}

	if (*commandNumber < 0 || *commandNumber > 3)
	{
		printf("Неверный номер комманды: %s\n", *commandNumber);
		printHelp();
	}

	int data = 0;
	switch (*commandNumber)
	{
		case 0:
			break;

		case 1:
			sscanf(buffer + commandOffset, " %d", data);
			insertElementToList(list, data, &printInsertingData);
			break;

		case 2:
			sscanf(buffer + commandOffset, " %d", data);
			deleteElmentFromList(list, data, &printDeletingData);
			break;

		case 3:
			sscanf(buffer + commandOffset, " %d", data);
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
				printf("Неверный аргумент комманды: (%s)\n", data);
				printHelp();
				break;
			}
			break;

		default:
			printf("Неверный номер комманды: %s\n", *commandNumber);
			printHelp();
			break;
	}
}