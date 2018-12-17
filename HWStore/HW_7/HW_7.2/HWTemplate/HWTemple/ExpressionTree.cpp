#include "pch.h"
#include "ExpressionTree.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

enum MyEnum
{
	NUM,
	OP_SUM,
	OP_SUB,
	OP_MUL,
	OP_DIV
};

struct Token
{
	MyEnum tokenType = MyEnum(NUM);
	int number = 0;
};

struct Node
{
	Token data;
	Node *parent;
	Node *left;
	Node *right;
};

ExpressionTree::ExpressionTree()
{
}


ExpressionTree::~ExpressionTree()
{
}

Node *getNewNode(Node *parent, string &expression)
{
	stringstream str;
	str << expression;
	char ch;
	str.get(); //считали (

	Token newToken;
	ch = str.get(); //считали операцию
	switch (ch)
	{
	case '+':
		newToken.tokenType = MyEnum(OP_SUM);
		break;

	case '-':
		newToken.tokenType = MyEnum(OP_SUB);
		break;

	case '*':
		newToken.tokenType = MyEnum(OP_MUL);
		break;

	case '/':
		newToken.tokenType = MyEnum(OP_DIV);
		break;
	}
	auto newNode = new Node{ newToken, parent, nullptr, nullptr };

	str.get(); // считали пробел
	ch = str.get(); //считали либо (, либо число
	if (ch == '(')
	{
		{
			string newExpression;
			newExpression.push_back(ch);
			while (ch != ')')
			{
				ch = str.get();
				newExpression.push_back(ch);
			}
			newNode->left = getNewNode(newNode, newExpression);
		}
	}
	else
	{
		str.unget();
		{
			int number = 0;
			str >> number;
			Token newSublingToken{ MyEnum(NUM), number };
			newNode->left = new Node{ newSublingToken, newNode, nullptr, nullptr };
		}
	}

	str.get(); // считали пробел между 2-мя "числами"

	ch = str.get(); //считали либо (, либо число
	if (ch == '(')
	{
		{
			string newExpression;
			newExpression.push_back(ch);
			while (ch != ')')
			{
				ch = str.get();
				newExpression.push_back(ch);
			}
			newNode->right = getNewNode(newNode, newExpression);
		}
	}
	else
	{
		str.unget();
		{
			int number = 0;
			str >> number;
			Token newSublingToken{ MyEnum(NUM), number };
			newNode->right = new Node{ newSublingToken, newNode, nullptr, nullptr };
		}
	}

	str.get(); //считали )
	return newNode;
}


void ExpressionTree::readExpressionTree(string &expression)
{
	deleteAll();
	root = getNewNode(nullptr, expression);
}

void ExpressionTree::deleteAll(Node *currentNode, bool isFirst)
{
	if (isFirst)
	{
		currentNode = root;
		if (root == nullptr)
		{
			return;
		}
		isFirst = false;
	}

	if (currentNode == nullptr)
	{
		return;
	}

	deleteAll(currentNode->left, isFirst);
	deleteAll(currentNode->right, isFirst);

	delete currentNode;
}

int ExpressionTree::countExpression(Node *currentNode, bool isFirst) const
{
	if (isFirst)
	{
		currentNode = root;
		if (root == nullptr)
		{
			return 0;
		}
		isFirst = false;
	}

	if (currentNode->data.tokenType == MyEnum(NUM) || currentNode == nullptr)
	{
		return 0;
	}

	countExpression(currentNode->left, isFirst);
	countExpression(currentNode->right, isFirst);

	int operand1 = currentNode->left->data.number;
	int operand2 = currentNode->right->data.number;
	switch (currentNode->data.tokenType)
	{
		case OP_SUM:
			currentNode->data.number = operand1 + operand2;
			break;

		case OP_SUB:
			currentNode->data.number = operand1 - operand2;
			break;

		case OP_MUL:
			currentNode->data.number = operand1 * operand2;
			break;

		case OP_DIV:
			currentNode->data.number = operand1 / operand2;
			break;
	}

	return currentNode->data.number;
}
