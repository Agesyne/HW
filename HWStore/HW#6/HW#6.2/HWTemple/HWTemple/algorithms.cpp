#include "pch.h"
#include "algorithms.h"
#include <iostream>
#include <stack>
#include <string>
using namespace std;

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

bool isOpeningBracket(const char symbol)
{
	switch (symbol)
	{
	case '(':
	case '{':
	case '[':
		return true;
	default:
		return false;
	}
}

char getReverseBracket(const char symbol)
{
	switch (symbol)
	{
	case ')':
		return '(';
	case ']':
		return '[';
	case '}':
		return '{';
	default:
		return '#';
	}
}

bool isCorrectBracketsString(string &checkingString)
{
	stack<char> bracketsStack;
	if (checkingString.back() == '\n')
	{
		checkingString.erase(checkingString.end() - 1);
	}

	for (const char &symbol : checkingString)
	{
		if (isOpeningBracket(symbol))
		{
			bracketsStack.emplace(symbol);
		}
		else
		{
			if (bracketsStack.empty())
			{
				return false;
			}
			if (bracketsStack.top() == getReverseBracket(symbol))
			{
				bracketsStack.pop();
			}
		}
	}
	if (!bracketsStack.empty())
	{
		return false;
	}
	return true;
}