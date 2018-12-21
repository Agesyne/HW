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
	char name[32]{};
	char phoneNumber[20]{};
	sscanf(buffer, "���: %[A-z], ���������� �����: %s", &name, &phoneNumber);

	phoneNumberRecord *newRecord = new phoneNumberRecord{};
	for (int i = 0; i < 32; i++)
	{
		if (i < 20)
		{
			newRecord->phoneNumber[i] = phoneNumber[i];
		}
		newRecord->name[i] = name[i];
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
	int commandOffset = 0;
	sscanf(buffer, "%d%n", commandNumber, &commandOffset);

	if (*commandNumber < 0 || *commandNumber > 5)
	{
		printf("�������� ����� ��������: %d\n", *commandNumber);
		printHelp();
		return;
	}

	phoneNumberRecord *newRecord = new phoneNumberRecord{};
	char *name = new char[100]{};
	int inputtedNameLength = 0;
	char *phoneNumber = new char[100]{};
	int inputtedNumberLength = 0;
	Node *askedData = nullptr;
	int order = 0;
	char *url = new char[100]{};
	int urlLength = 0;
	int counter = 0;
	char ch = 0;
	switch (*commandNumber)
	{
	case 0:
		break;

	case 1:
		sscanf(buffer + commandOffset, " %s %s", name, phoneNumber);
		if (name[0] == '\0' || phoneNumber[0] == '\0')
		{
			printf("�������� ��������� ��������: (%s) (%s)\n", name, phoneNumber);
			printHelp();
			break;
		}

		inputtedNameLength = strlen(name);
		if (inputtedNameLength > 32)
		{
			printf("�������� ������ ����� (������ 32 ��������): %s\n", name);
			break;
		}

		for (int i = 0; i < 32; i++)
		{
			if (i >= inputtedNameLength)
			{
				break;
			}
			newRecord->name[i] = name[i];
		}

		inputtedNumberLength = strlen(phoneNumber);
		if (inputtedNumberLength > 20)
		{
			printf("�������� ������ ������ (������ 20 ��������): %s\n", phoneNumber);
			break;
		}
		for (int i = 0; i < 20; i++)
		{
			if (i >= inputtedNumberLength)
			{
				break;
			}
			newRecord->phoneNumber[i] = phoneNumber[i];
		}

		insertNode(dataBaseByName, newRecord, &compareIfLessOrEqualByName);
		insertNode(dataBaseByNumber, newRecord, &compareIfLessOrEqualByNumber);

		printf("������ ���������\n");
		break;

	case 2:
		sscanf(buffer + commandOffset, " %d", &order);
		if (order == 0)
		{
			printAllData(dataBaseByName);
		}
		else if (order == 1)
		{
			printAllData(dataBaseByNumber);
		}
		else
		{
			printf("�������� �������� ��������: (%dq)\n", order);
			printHelp();
		}
		break;

	case 3:
		sscanf(buffer + commandOffset, " %s", name);
		if (name[0] == '\0')
		{
			printf("�������� �������� ��������: (%s)\n", name);
			printHelp();
			break;
		}
		inputtedNameLength = strlen(name);
		if (inputtedNameLength > 32)
		{
			printf("�������� ������ ����� (������ 32 ��������): %s\n", name);
			break;
		}

		for (int i = 0; i < 32; i++)
		{
			if (i >= inputtedNameLength)
			{
				break;
			}
			newRecord->name[i] = name[i];
		}

		askedData = findData(dataBaseByName, newRecord, &compareIfEqualByName, &compareIfLessOrEqualByName, &printData);
		if (askedData == nullptr || askedData == LEAF)
		{
			printf("������ �������� ��� � ��\n");
			break;
		}
		break;

	case 4:
		sscanf(buffer + commandOffset, " %s", phoneNumber);
		if (phoneNumber[0] == '\0')
		{
			printf("�������� �������� ��������: (%s)\n", phoneNumber);
			printHelp();
			break;
		}
		inputtedNumberLength = strlen(phoneNumber);
		if (inputtedNumberLength > 32)
		{
			printf("�������� ������ ������ (������ 20 ��������): %s\n", phoneNumber);
			break;
		}
		for (int i = 0; i < 20; i++)
		{
			if (i >= inputtedNumberLength)
			{
				break;
			}
			newRecord->phoneNumber[i] = phoneNumber[i];
		}


		askedData = findData(dataBaseByNumber, newRecord, &compareIfEqualByNumber, &compareIfLessOrEqualByNumber, &printData);
		if (askedData == nullptr || askedData == LEAF)
		{
			printf("������ ������ ��� � ��\n");
			break;
		}
		break;

	case 5:
		sscanf(buffer + commandOffset, " %[0-9A-Za-z]%n.", url, &counter);
		if (buffer[commandOffset + counter] != '.')
		{
			printf("����������� ������: (%c) �����: (%s)\n", buffer[commandOffset + counter], url);
			break;
		}
		url[counter - 1] = '.';

		sscanf(buffer + commandOffset + counter + 1, "%[a-z] %d",url + counter, &order);

		if (url[0] != '\0' && order == 0)
		{
			saveDataBaseToFile(url, dataBaseByName);
		}
		else if (url[0] != '\0' && order == 1)
		{
			saveDataBaseToFile(url, dataBaseByNumber);
		}
		else
		{
			printf("�������� �������� ��������: (%s %d)\n", url, order);
			break;
		}

		printf("�� ���� ��������� � %s\n", url);
		break;

	default:
		printf("�������� ����� ��������: %s\n", *commandNumber);
		printHelp();
		break;
	}

	delete newRecord;
	delete name;
	delete phoneNumber;
	delete url;
}