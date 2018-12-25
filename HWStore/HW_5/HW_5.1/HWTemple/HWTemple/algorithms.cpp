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
	const int maxNumberCommandArgument = 2;
	char *commandArgument[maxNumberCommandArgument]{};
	bool isDataNext = true;
	int dataCounter = 0;

	for (int charCounter = 0; buffer[charCounter] != '\n' && buffer[charCounter] != '\0'; charCounter++)
	{
		if (buffer[charCounter] == ' ' && !isDataNext)
		{
			isDataNext = true;
			continue;
		}

		if (isDataNext)
		{
			int dataLength = 0;
			for (int i = 0;;)
			{
				bool isStillData = isspace(buffer[charCounter + 1]) != 0;
				if (isStillData)
				{
					i++;
				}
				else
				{
					dataLength = i;
					break;
				}
			}

			char *dataFromString = new char[100]{};
			for (int i = 0; i < dataLength; i++)
			{
				dataFromString[i] = buffer[charCounter + i];
			}

			if (dataCounter >= maxNumberCommandArgument)
			{
				printf("Лишний аргумент комманды: (%s)\n", dataFromString);
				printHelp();
				for (int i = 0; i < maxNumberCommandArgument; i++)
				{
					delete[] commandArgument[i];
				}
				delete[] dataFromString;
				return;
			}
			commandArgument[dataCounter++] = dataFromString;

			charCounter += dataLength - 1;
			isDataNext = false;
			continue;
		}
	}

	if (strlen(commandArgument[0]) > 1 || !isdigit(commandArgument[0][0]))
	{
		printf("Неверный номер комманды: %s\n", commandArgument[0]);
		printHelp();
		for (int i = 0; i < maxNumberCommandArgument; i++)
		{
			delete[] commandArgument[i];
		}
		return;
	}
	*commandNumber = commandArgument[0][0] - '0';

	int data = 0;
	int sign = 1;
	int argumentLength = 0;
	int argumentCharCounter = 0;
	bool hasBadArgument = false;
	switch (*commandNumber)
	{
		case 0:
			if (commandArgument[1] != nullptr)
			{
				printf("Лишний аргумент комманды: (%s)\n", commandArgument[1]);
				*commandNumber = -1;
			}
		break;

		case 1:
			if (commandArgument[1] == nullptr)
			{
				printf("Неверный аргумент комманды: (%s)\n", commandArgument[1]);
				printHelp();
				break;
			}

			argumentLength = strlen(commandArgument[1]);
			if (argumentLength > 10)
			{
				printf("Неверный аргумент комманды (больше 10 символов): (%s)\n", commandArgument[1]);
				printHelp();
				break;
			}

			if (commandArgument[1][0] == '-' || commandArgument[1][0] == '+')
			{
				if (commandArgument[1][0] == '-')
				{
					sign = -1;
				}
				argumentCharCounter++;
			}

			for (; argumentCharCounter < argumentLength; argumentCharCounter++)
			{
				if (!isdigit(commandArgument[1][argumentCharCounter]))
				{
					printf("Неверный аргумент комманды: (%s)\n", commandArgument[1]);
					hasBadArgument = true;
					break;
				}
				data = data * 10 + (commandArgument[1][argumentCharCounter] - '0');
			}

			if (hasBadArgument)
			{
				break;
			}

			data *= sign;

			insertElementToList(list, data, &printInsertingData);
		break;

		case 2:
			if (commandArgument[1] == nullptr)
			{
				printf("Неверный аргумент комманды: (%s)\n", commandArgument[1]);
				printHelp();
				break;
			}
			argumentLength = strlen(commandArgument[1]);
			if (argumentLength > 10)
			{
				printf("Неверный аргумент комманды (больше 10 символов): (%s)\n", commandArgument[1]);
				printHelp();
				break;
			}

			if (commandArgument[1][0] == '-' || commandArgument[1][0] == '+')
			{
				if (commandArgument[1][0] == '-')
				{
					sign = -1;
				}
				argumentCharCounter++;
			}

			for (; argumentCharCounter < argumentLength; argumentCharCounter++)
			{
				if (!isdigit(commandArgument[1][argumentCharCounter]))
				{
					printf("Неверный аргумент комманды: (%s)\n", commandArgument[1]);
					hasBadArgument = true;
					break;
				}
				data = data * 10 + (commandArgument[1][argumentCharCounter] - '0');
			}

			if (hasBadArgument)
			{
				break;
			}

			data *= sign;

			deleteElmentFromList(list, data, &printDeletingData);
		break;

		case 3:
			if (commandArgument[1] == nullptr || (strlen(commandArgument[1]) == 1 && commandArgument[1][0] == '0'))
			{
				printAllData(list);
			}
			else if (strlen(commandArgument[1]) == 1 && commandArgument[1][0] == '1')
			{
				printAllData(list, false);
			}
			else
			{
				printf("Неверный аргумент комманды: (%s)\n", commandArgument[1]);
				printHelp();
				break;
			}
		break;

		default:
			printf("Неверный номер комманды: %s\n", commandArgument[0]);
			printHelp();
		break;
	}

	for (int i = 0; i < maxNumberCommandArgument; i++)
	{
		delete[] commandArgument[i];
	}
}