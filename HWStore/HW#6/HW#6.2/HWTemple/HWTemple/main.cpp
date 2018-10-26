#include "pch.h"
#include <iostream>
#include "check.h"
#include "initialization.h"
#include "algorithms.h"
#include <string>
using namespace std;


int main()
{
	setlocale(LC_ALL, "RUS");
	checkFromFile();

	string bracketsString;
	cout << "Введите строку: ";
	getline(cin, bracketsString);

	const bool isCorrentString = isCorrectBracketsString(bracketsString);
	
	cout << ((isCorrentString) ? "Верная строка" : "Неверная строка") << endl;

	return 0;
}
