#include "pch.h"
#include <iostream>
#include <string.h>
#include "initialization.h"
#include "dataStructures.h"
#include "saveToFile.h"


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


bool compareIfEqualByName(phoneNumberRecord a, phoneNumberRecord b)
{
	return strcmp(a.name,b.name) == 0;
}
bool compareIfLessOrEqualByName(phoneNumberRecord a, phoneNumberRecord b)
{
	return strcmp(a.name, b.name) <= 0;
}

bool compareIfEqualByNumber(phoneNumberRecord a, phoneNumberRecord b)
{
	return strcmp(a.phoneNumber, b.phoneNumber) == 0;
}
bool compareIfLessOrEqualByNumber(phoneNumberRecord a, phoneNumberRecord b)
{
	return strcmp(a.phoneNumber, b.phoneNumber) <= 0;
}

bool printData(phoneNumberRecord a)
{
	printf("���: %s\t�����: %s\n", a.name, a.phoneNumber);
	return false;
}


void processInputString(const char buffer[], BlackRedTree *dataBaseByName, BlackRedTree *dataBaseByNumber)
{
	bool isDataNext = false;
	int dataCounter = 0;
	phoneNumberRecord *newRecord = new phoneNumberRecord{};

	for (int charCounter = 0; buffer[charCounter] != '\n' && buffer[charCounter] != '\0'; charCounter++)
	{
		if (buffer[charCounter] == ':')
		{
			isDataNext = true;
			dataCounter++;
			charCounter++;
			continue;
		}

		if (isDataNext)
		{
			int dataLength = 0;
			for (int i = 0;;)
			{
				bool isStillData =	(buffer[charCounter + i] != ',') 
									&& (buffer[charCounter + i] != '\n') 
									&& (buffer[charCounter + i] != '\0')
									&& (buffer[charCounter + i] != ' ');
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

			char dataFromString[50]{};
			for (int i = 0; i < dataLength; i++)
			{
				dataFromString[i] = buffer[charCounter + i];
			}

			int inputtedNameLength = 0;
			int inputtedNumberLength = 0;
			switch (dataCounter)
			{
				case 1:
					inputtedNameLength = strlen(dataFromString);
					if (inputtedNameLength > 32)
					{
						printf("�������� ������ ����� (������ 32 ��������): %s\n", dataFromString);
						break;
					}
					for (int i = 0; i < 32; i++)
					{
						if (i >= inputtedNameLength)
						{
							break;
						}
						newRecord->name[i] = dataFromString[i];
					}
				break;

				case 2:
					inputtedNumberLength = strlen(dataFromString);
					if (inputtedNumberLength > 20)
					{
						printf("�������� ������ ������ (������ 20 ��������): %s\n", dataFromString);
						break;
					}
					for (int i = 0; i < 20; i++)
					{
						if (i >= inputtedNumberLength)
						{
							break;
						}
						newRecord->phoneNumber[i] = dataFromString[i];
					}
				break;

				default:
					printf("������ ���������� ������: (%s)\n", dataFromString);
					printf("� ������: (%s)\n", buffer);
					return;
				break;
			}

			charCounter += dataLength - 1;
			isDataNext = false;
			continue;
		}
	}
	insertNode(dataBaseByName, newRecord, &compareIfLessOrEqualByName);
	insertNode(dataBaseByNumber, newRecord, &compareIfLessOrEqualByNumber);
	delete newRecord;
}

void printBannedSymbols(char bannedSymbols[9])
{
	printf("������ ������������ �������: ");
	for (int i = 0; i < 8; i++)
	{
		printf("%c, ", bannedSymbols[i]);
	}
	printf("%C\n", bannedSymbols[8]);
}

void printHelp()
{
	printf("������ �������:\n");
	printf("   ->���������\n"); 
	printf("      |---------------------------------------------------------|\n");
	printf("\t��� ������ ���� �������. ������� Windows\n");
	printf("\t����� � �������: +���_������(��� ������/����)888-88-88\n");
	printf("\t��� ������: 0 ��� \"\" - �� ������, 1 - �� �������\n");
	printf("      |---------------------------------------------------------|\n");
	printf("   ->����� �� ���������:\t\"0\"\n");
	printf("   ->�������� ������ � ��:\t\"1 ��� �����\"\n");
	printf("   ->����������� ��� ��:\t\"2 ���_������\" \n");
	printf("   ->����� ����� �� �����:\t\"3 ���\"\n");
	printf("   ->����� ��� �� ������:\t\"4 �����\"\n");
	printf("   ->��������� �� � ����:\t\"5 ���_����� ���_������\"\n");

	printf("\n");
}

void processInputCommand(const char buffer[], BlackRedTree *dataBaseByName, BlackRedTree *dataBaseByNumber, int *commandNumber)
{
	const int maxNumberCommandArgument = 3;
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
				bool isStillData = (buffer[charCounter + i] != ' ')
								&& (buffer[charCounter + i] != '\n')
								&& (buffer[charCounter + i] != '\0');
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
				printf("������ �������� �������: (%s)\n", dataFromString);
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
		printf("�������� ����� ��������: %s\n", commandArgument[0]);
		printHelp();
		for (int i = 0; i < maxNumberCommandArgument; i++)
		{
			delete[] commandArgument[i];
		}
		return;
	}
	*commandNumber = commandArgument[0][0] - '0';

	int inputtedNameLength = 0;
	int inputtedNumberLength = 0;
	phoneNumberRecord *newRecord = new phoneNumberRecord{};
	Node *askedData = nullptr;
	int urlLength = 0;
	char bannedSymbols[9] = { '\\', '/' , '|' ,':','*', '?' , '\"', '<', '>' };
	bool isDotAppeared = false;
	bool isBadSymbolsInURL = false;
	switch (*commandNumber)
	{
		case 0:
		break;

		case 1:
			if (commandArgument[1] == nullptr || commandArgument[2] == nullptr)
			{
				printf("�������� ��������� ��������: (%s), (%s)\n", commandArgument[1], commandArgument[2]);
				printHelp();
				break;
			}

			inputtedNameLength = strlen(commandArgument[1]);
			if (inputtedNameLength > 32)
			{
				printf("�������� ������ ����� (������ 32 ��������): %s\n", commandArgument[1]);
				break;
			}

			for (int i = 0; i < 32; i++)
			{
				if (i >= inputtedNameLength)
				{
					break;
				}
				newRecord->name[i] = commandArgument[1][i];
			}

			inputtedNumberLength = strlen(commandArgument[2]);
			if (inputtedNumberLength > 20)
			{
				printf("�������� ������ ������ (������ 20 ��������): %s\n", commandArgument[2]);
				break;
			}
			for (int i = 0; i < 20; i++)
			{
				if (i >= inputtedNumberLength)
				{
					break;
				}
				newRecord->phoneNumber[i] = commandArgument[2][i];
			}

			insertNode(dataBaseByName, newRecord, &compareIfLessOrEqualByName);
			insertNode(dataBaseByNumber, newRecord, &compareIfLessOrEqualByNumber);
			

			printf("������ ���������\n");
		break;

		case 2:
			if (commandArgument[1] == nullptr || (strlen(commandArgument[1]) == 1 && commandArgument[1][0] == '0'))
			{
				printAllData(dataBaseByName);
			}
			else if (strlen(commandArgument[1]) == 1 && commandArgument[1][0] == '1')
			{
				printAllData(dataBaseByNumber);
			}
			else
			{
				printf("�������� �������� ��������: (%s)\n", commandArgument[1]);
				printHelp();
			}
		break;

		case 3:
			if (commandArgument[1] == nullptr)
			{
				printf("�������� �������� ��������: (%s)\n", commandArgument[1]);
				printHelp();
				break;
			}
			inputtedNameLength = strlen(commandArgument[1]);
			if (inputtedNameLength > 32)
			{
				printf("�������� ������ ����� (������ 32 ��������): %s\n", commandArgument[1]);
				break;
			}

			for (int i = 0; i < 32; i++)
			{
				if (i >= inputtedNameLength)
				{
					break;
				}
				newRecord->name[i] = commandArgument[1][i];
			}

			askedData = findData(dataBaseByName, newRecord, &compareIfEqualByName, &compareIfLessOrEqualByName, &printData);

			if (askedData == nullptr || askedData == LEAF)
			{
				printf("������ �������� ��� � ��\n");
				break;
			}
		break;

		case 4:
			if (commandArgument[1] == nullptr)
			{
				printf("�������� �������� ��������: (%s)\n", commandArgument[1]);
				printHelp();
				break;
			}
			inputtedNumberLength = strlen(commandArgument[1]);
			if (inputtedNumberLength > 32)
			{
				printf("�������� ������ ������ (������ 20 ��������): %s\n", commandArgument[1]);
				break;
			}
			for (int i = 0; i < 20; i++)
			{
				if (i >= inputtedNumberLength)
				{
					break;
				}
				newRecord->phoneNumber[i] = commandArgument[1][i];
			}


			askedData = findData(dataBaseByNumber, newRecord, &compareIfEqualByNumber, &compareIfLessOrEqualByNumber, &printData);

			if (askedData == nullptr || askedData == LEAF)
			{
				printf("������ ������ ��� � ��\n");
				break;
			}
		break;

		case 5:
			if (commandArgument[1] == nullptr)
			{
				printf("�������� �������� ��������: (%s)\n", commandArgument[1]);
				printHelp();
				break;
			}
			urlLength = strlen(commandArgument[1]);
			isDotAppeared = false;
			for (int i = 0; i < urlLength; i++)
			{
				for (int j = 0; j < 9; j++)
				{
					if (commandArgument[1][i] == bannedSymbols[j])
					{
						printf("������������ ������� � �������� �����: %s\n", commandArgument[1]);
						printBannedSymbols(bannedSymbols);
						isBadSymbolsInURL = true;
						break;
						//� ����� ����� goto, ����� ���� � ���. �������� ����� �� ������? 
					}
				}

				if (isBadSymbolsInURL)
				{
					break;
				}

				if (commandArgument[1][i] == '.')
				{
					isDotAppeared = true;
				}
			}

			if (isBadSymbolsInURL)
			{
				break;
			}

			if (!isDotAppeared)
			{
				printf("�� ������� ���������� �����: %s\n", commandArgument[1]);
				break;
			}

			if (commandArgument[2] == nullptr || (strlen(commandArgument[2]) == 1 && commandArgument[2][0] == '0'))
			{
				saveDataBaseToFile(commandArgument[1], dataBaseByName);
			}
			else if (strlen(commandArgument[2]) == 1 && commandArgument[2][0] == '1')
			{
				saveDataBaseToFile(commandArgument[1], dataBaseByNumber);
			}
			else
			{
				printf("�������� �������� ��������: (%s)\n", commandArgument[2]);
				break;
			}

			printf("�� ���� ��������� � %s\n", commandArgument[1]);
		break;

		default:
			printf("�������� ����� ��������: %s\n", commandArgument[0]);
			printHelp();
		break;
	}
	delete newRecord;
	for (int i = 0; i < maxNumberCommandArgument; i++)
	{
		delete[] commandArgument[i];
	}
}