#pragma once
#include <iostream>
using namespace std;

int max(const int number1, const int number2);

void swap(int *a, int *b);

bool isOpeningBracket(const char symbol);

char getReverseBracket(const char symbol);

bool isCorrectBracketsString(string &checkingString);
