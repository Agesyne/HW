#pragma once
#include <iostream>
#include <string>

extern struct Node;

class ExpressionTree
{
private:
	Node *root = nullptr;
public:
	ExpressionTree();
	~ExpressionTree();

	void readExpressionTree(std::string &expression);

	void deleteAll(Node *rootNode = nullptr, bool isFirst = true);

	int countExpression(Node *rootNode = nullptr, bool isFirst = true) const;
};

