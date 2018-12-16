#include "pch.h"
#include "algorithms.h"
#include <iostream>
#include "Stack.h"
#include <string>
using namespace std;


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
	Stack<char> bracketsStack;
	if (checkingString.back() == '\n')
	{
		checkingString.erase(checkingString.end() - 1);
	}

	for (const char &symbol : checkingString)
	{
		if (isOpeningBracket(symbol))
		{
			bracketsStack.push(symbol);
		}
		else
		{
			if (bracketsStack.isEmpty())
			{
				return false;
			}
			if (bracketsStack.peak() == getReverseBracket(symbol))
			{
				bracketsStack.pop();
			}
		}
	}

	return ((bracketsStack.isEmpty()) ? true : false);
}