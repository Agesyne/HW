#include "pch.h"
#include <iostream>
#include <string.h>
#include "initialization.h"
#include "dataStructures.h"
#include "saveToFile.h"

const int maxSizeOfNameBuffer = 32;
const int maxSizeOfPhoneNumberBuffer = 20;

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


bool compareIfEqualByName(PhoneNumberRecord a, PhoneNumberRecord b)
{
	return strcmp(a.name, b.name) == 0;
}

bool compareIfLessOrEqualByName(PhoneNumberRecord a, PhoneNumberRecord b)
{
	return strcmp(a.name, b.name) <= 0;
}

bool compareIfEqualByNumber(PhoneNumberRecord a, PhoneNumberRecord b)
{
	return strcmp(a.phoneNumber, b.phoneNumber) == 0;
}

bool compareIfLessOrEqualByNumber(PhoneNumberRecord a, PhoneNumberRecord b)
{
	return strcmp(a.phoneNumber, b.phoneNumber) <= 0;
}

bool printData(PhoneNumberRecord a)
{
	printf("Имя: %s\tНомер: %s\n", a.name, a.phoneNumber);
	return false;
}

void processInputString(const char buffer[], BlackRedTree *dataBaseByName, BlackRedTree *dataBaseByNumber)
{
	char name[maxSizeOfNameBuffer]{};
	char phoneNumber[maxSizeOfPhoneNumberBuffer]{};
	sscanf(buffer, "Имя: %[A-z], Телефонный номер: %s", &name, &phoneNumber);

	PhoneNumberRecord *newRecord = new PhoneNumberRecord{};
	strcpy(newRecord->phoneNumber, phoneNumber);
	strcpy(newRecord->name, name);

	insertNode(dataBaseByName, newRecord, &compareIfLessOrEqualByName);
	insertNode(dataBaseByNumber, newRecord, &compareIfLessOrEqualByNumber);
	delete newRecord;
}

void printBannedSymbols(char bannedSymbols[9])
{
	printf("Список недопустимых сиволов: ");
	for (int i = 0; i < 8; i++)
	{
		printf("%c, ", bannedSymbols[i]);
	}
	printf("%C\n", bannedSymbols[8]);
}

void printHelp()
{
	printf("Список комманд:\n");
	printf("   ->Пояснение\n"); 
	printf("      |---------------------------------------------------------|\n");
	printf("\tИмя писать англ буквами. Спасибо Windows\n");
	printf("\tНомер в формате: +код_страны(код города/сети)888-88-88\n");
	printf("\tТип вывода: 0 или \"\" - по именам, 1 - по номерам\n");
	printf("      |---------------------------------------------------------|\n");
	printf("   ->Выйти из программы:\t\"0\"\n");
	printf("   ->Добавить запись в БД:\t\"1 Имя Номер\"\n");
	printf("   ->Распечатать всю БД:\t\"2 Тип_вывода\" \n");
	printf("   ->Найти номер по имени:\t\"3 Имя\"\n");
	printf("   ->Найти имя по номеру:\t\"4 Номер\"\n");
	printf("   ->Сохранить БД в файл:\t\"5 Имя_файла Тип_вывода\"\n");

	printf("\n");
}

void processInputCommand(const char buffer[], BlackRedTree *dataBaseByName, BlackRedTree *dataBaseByNumber, int *commandNumber)
{
	int commandOffset = 0;
	sscanf(buffer, "%d%n", commandNumber, &commandOffset);

	if (*commandNumber < 0 || *commandNumber > 5)
	{
		printf("Неверный номер комманды: %d\n", *commandNumber);
		printHelp();
		return;
	}

	PhoneNumberRecord *newRecord = new PhoneNumberRecord{};
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
			printf("Неверные аргументы комманды: (%s) (%s)\n", name, phoneNumber);
			printHelp();
			break;
		}

		inputtedNameLength = strlen(name);
		if (inputtedNameLength > maxSizeOfNameBuffer)
		{
			printf("Неверный формат имени (больше 32 символов): %s\n", name);
			break;
		}
		strcpy(newRecord->name, name);

		inputtedNumberLength = strlen(phoneNumber);
		if (inputtedNumberLength > maxSizeOfPhoneNumberBuffer)
		{
			printf("Неверный формат номера (больше 20 символов): %s\n", phoneNumber);
			break;
		}
		strcpy(newRecord->phoneNumber, phoneNumber);

		insertNode(dataBaseByName, newRecord, &compareIfLessOrEqualByName);
		insertNode(dataBaseByNumber, newRecord, &compareIfLessOrEqualByNumber);

		printf("Запись добавлена\n");
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
			printf("Неверный аргумент комманды: (%dq)\n", order);
			printHelp();
		}
		break;

	case 3:
		sscanf(buffer + commandOffset, " %s", name);
		if (name[0] == '\0')
		{
			printf("Неверный аргумент комманды: (%s)\n", name);
			printHelp();
			break;
		}
		inputtedNameLength = strlen(name);
		if (inputtedNameLength > maxSizeOfNameBuffer)
		{
			printf("Неверный формат имени (больше 32 символов): %s\n", name);
			break;
		}

		strcpy(newRecord->name, name);

		askedData = findData(dataBaseByName, newRecord, &compareIfEqualByName, &compareIfLessOrEqualByName, &printData);
		if (askedData == nullptr || askedData == LEAF)
		{
			printf("Такого человека нет в БД\n");
			break;
		}
		break;

	case 4:
		sscanf(buffer + commandOffset, " %s", phoneNumber);
		if (phoneNumber[0] == '\0')
		{
			printf("Неверный аргумент комманды: (%s)\n", phoneNumber);
			printHelp();
			break;
		}
		inputtedNumberLength = strlen(phoneNumber);
		if (inputtedNumberLength > maxSizeOfNameBuffer)
		{
			printf("Неверный формат номера (больше 20 символов): %s\n", phoneNumber);
			break;
		}
		strcpy(newRecord->phoneNumber, phoneNumber);


		askedData = findData(dataBaseByNumber, newRecord, &compareIfEqualByNumber, &compareIfLessOrEqualByNumber, &printData);
		if (askedData == nullptr || askedData == LEAF)
		{
			printf("Такого номера нет в БД\n");
			break;
		}
		break;

	case 5:
		sscanf(buffer + commandOffset, " %[0-9A-Za-z]%n.", url, &counter);
		if (buffer[commandOffset + counter] != '.')
		{
			printf("Запрещённый символ: (%c) после: (%s)\n", buffer[commandOffset + counter], url);
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
			printf("Неверный аргумент комманды: (%s %d)\n", url, order);
			break;
		}

		printf("БД была сохранена в %s\n", url);
		break;

	default:
		printf("Неверный номер комманды: %s\n", *commandNumber);
		printHelp();
		break;
	}

	delete newRecord;
	delete name;
	delete phoneNumber;
	delete url;
}