#include "pch.h"
#include "algorithms.h"
#include <iostream>
#include <string>
#include "Stack.h"
using namespace std;


int getPriority(const char symbol)
{
	switch (symbol)
	{
	case '+':
	case '-':
		return 2;
	case '*':
	case '/':
		return 3;
	case '(':
	case ')':
	case '#':
		return 1;
	default:
		return 0;
	}
}

string translateToPostfix(string infixString)
{
	string postfix = "";
	//Stack<char> *operatorStack = new Stack<char>();
	Stack<char> operatorStack;
	operatorStack.push('#');
	
	for (const auto &i : infixString)
	{
		if (i == ' ')
		{
			continue;
		}

		if (isdigit(i))
		{
			postfix.push_back(i);
		}
		else
		{
			if (i == '(')
			{
				operatorStack.push('(');
			}
			else
			{
				if (i == ')')
				{
					while (operatorStack.peak() != '(')
					{
						postfix.push_back(operatorStack.peak());
						operatorStack.pop();
					}
					operatorStack.pop();
				}
				else
				{
					if (getPriority(i) > getPriority(operatorStack.peak()))
					{
						operatorStack.push(i);
					}
					else
					{
						while (getPriority(i) <= getPriority(operatorStack.peak()))
						{
							postfix.push_back(operatorStack.peak());
							operatorStack.pop();
						}
						operatorStack.push(i);
					}
				}
			}
		}
	}
	while (operatorStack.peak() != '#')
	{
		postfix.push_back(operatorStack.peak());
		operatorStack.pop();
	}
	//operatorStack->~Stack;

	return postfix;
}