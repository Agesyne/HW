#include "pch.h"
#include "algorithms.h"
#include "Stack.h"
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
	Stack<int> calculatingStack;

	for (const char &i : inputCalculatingData)
	{
		if (isdigit(i))
		{
			calculatingStack.push(static_cast<int>(i) - '0');
		}
		else
		{
			int operand2;
			int operand1;
			switch (i)
			{
			case '+':
				operand2 = calculatingStack.peak();
				calculatingStack.pop();

				operand1 = calculatingStack.peak();
				calculatingStack.pop();

				calculatingStack.push(operand1 + operand2);
			break;

			case '-':
				operand2 = calculatingStack.peak();
				calculatingStack.pop();

				operand1 = calculatingStack.peak();
				calculatingStack.pop();

				calculatingStack.push(operand1 - operand2);
			break;

			case '*':
				operand2 = calculatingStack.peak();
				calculatingStack.pop();

				operand1 = calculatingStack.peak();
				calculatingStack.pop();

				calculatingStack.push(operand1 * operand2);
			break;

			case '/':
				operand2 = calculatingStack.peak();
				calculatingStack.pop();

				operand1 = calculatingStack.peak();
				calculatingStack.pop();

				calculatingStack.push(operand1 / operand2);
				break;

			case ' ':
				continue;
			}
		}
	}
	
	int result = calculatingStack.peak();
	calculatingStack.pop();
	return result;
}