#include "pch.h"
#include "algorithms.h"
#include <stack>
#include <iostream>
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

int calculatePostFixForm(string &inputCalculatingData)
{
	stack<int> calculatingStack;

	for (const char &i : inputCalculatingData)
	{
		if (isdigit(i))
		{
			calculatingStack.emplace(static_cast<int>(i) - '0');
		}
		else
		{
			int operand2;
			int operand1;
			switch (i)
			{
			case '+':
				operand2 = calculatingStack.top();
				calculatingStack.pop();

				operand1 = calculatingStack.top();
				calculatingStack.pop();

				calculatingStack.emplace(operand1 + operand2);
			break;

			case '-':
				operand2 = calculatingStack.top();
				calculatingStack.pop();

				operand1 = calculatingStack.top();
				calculatingStack.pop();

				calculatingStack.emplace(operand1 - operand2);
			break;

			case '*':
				operand2 = calculatingStack.top();
				calculatingStack.pop();

				operand1 = calculatingStack.top();
				calculatingStack.pop();

				calculatingStack.emplace(operand1 * operand2);
			break;

			case '/':
				operand2 = calculatingStack.top();
				calculatingStack.pop();

				operand1 = calculatingStack.top();
				calculatingStack.pop();

				calculatingStack.emplace(operand1 / operand2);
				break;

			case ' ':
				continue;
			}
		}
	}
	
	int result = calculatingStack.top();
	calculatingStack.pop();
	return result;
}