#include "pch.h"
#include "algorithms.h"
#include "Stack.h"
#include <iostream>
using namespace std;

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
			int operand2 = calculatingStack.peak();
			calculatingStack.pop();

			int operand1 = calculatingStack.peak();
			calculatingStack.pop();
			switch (i)
			{
			case '+':
				calculatingStack.push(operand1 + operand2);
				break;

			case '-':
				calculatingStack.push(operand1 - operand2);
				break;

			case '*':
				calculatingStack.push(operand1 * operand2);
				break;

			case '/':
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