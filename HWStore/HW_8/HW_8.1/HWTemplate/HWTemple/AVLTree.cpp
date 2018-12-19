#include "pch.h"
#include "AVLTree.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct Node
{
	string key;
	string data;
	Node *parent;
	Node *left;
	Node *right;
	int heightLeft;
	int heightRight;
};

AVLTree::AVLTree()
{
}


AVLTree::~AVLTree()
{
	deleteAll();
}



void countNodeBalance(Node *currentNode)
{
	if (currentNode->left != nullptr)
	{
		currentNode->heightLeft = max(currentNode->left->heightLeft, currentNode->left->heightRight) + 1;
	}
	else
	{
		currentNode->heightLeft = 0;
	}
	if (currentNode->right != nullptr)
	{
		currentNode->heightRight = max(currentNode->right->heightLeft, currentNode->right->heightRight) + 1;
	}
	else
	{
		currentNode->heightRight = 0;
	}
}

void balanceTree(Node *aBalanceNode, Node *bBalanceNode, Node *cBalanceNode, Node **root)
{
	Node *aParent = aBalanceNode->parent;
	bool isLeftChild = true;
	if (aParent != nullptr)
	{
		isLeftChild = aParent->left == aBalanceNode;
	}

	Node *leftNode = nullptr;
	Node *rightNode = nullptr;
	Node *middleNode = nullptr;
	Node *subTree1 = nullptr;
	Node *subTree2 = nullptr;
	Node *subTree3 = nullptr;
	Node *subTree4 = nullptr;
	if (bBalanceNode == aBalanceNode->left)
	{
		if (cBalanceNode == bBalanceNode->left)
		{
			subTree1 = cBalanceNode->left;
			subTree2 = cBalanceNode->right;
			subTree3 = bBalanceNode->right;
			subTree4 = aBalanceNode->right;
			leftNode = cBalanceNode;
			rightNode = aBalanceNode;
			middleNode = bBalanceNode;
		}
		else
		{
			subTree1 = cBalanceNode->left;
			subTree2 = cBalanceNode->left;
			subTree3 = bBalanceNode->right;
			subTree4 = aBalanceNode->right;
			leftNode = bBalanceNode;
			rightNode = aBalanceNode;
			middleNode = cBalanceNode;
		}
	}
	else
	{
		if (cBalanceNode == bBalanceNode->left)
		{
			subTree1 = aBalanceNode->left;
			subTree2 = cBalanceNode->left;
			subTree3 = cBalanceNode->right;
			subTree3 = bBalanceNode->right;
			leftNode = aBalanceNode;
			rightNode = bBalanceNode;
			middleNode = cBalanceNode;
		}
		else
		{
			subTree1 = aBalanceNode->left;
			subTree2 = bBalanceNode->left;
			subTree3 = cBalanceNode->left;
			subTree4 = cBalanceNode->right;
			leftNode = aBalanceNode;
			rightNode = cBalanceNode;
			middleNode = bBalanceNode;
		}
	}

	if (aParent != nullptr)
	{
		if (isLeftChild)
		{
			aParent->left = middleNode;
		}
		else
		{
			aParent->right = middleNode;
		}
	}
	else
	{
		*root = middleNode;
	}
	middleNode->left = leftNode;
	middleNode->right = rightNode;
	middleNode->parent = aParent;

	leftNode->left = subTree1;
	subTree1->parent = leftNode;
	leftNode->right = subTree2;
	subTree2->parent = leftNode;
	leftNode->parent = middleNode;

	rightNode->left = subTree3;
	subTree3->parent = rightNode;
	rightNode->right = subTree4;
	subTree4->parent = rightNode;
	rightNode->parent = middleNode;

	countNodeBalance(leftNode);
	countNodeBalance(rightNode);
	countNodeBalance(middleNode);
}

void fixTree(Node *addedNode, Node **root)
{
	if (addedNode == *root || addedNode->parent == *root)
	{
		return;
	}
	Node *aBalanceNode = addedNode->parent->parent;
	Node *cBalanceNode = addedNode;
	Node *bBalanceNode = addedNode->parent;
	countNodeBalance(bBalanceNode);

	while (aBalanceNode != nullptr)
	{
		countNodeBalance(aBalanceNode);

		int bFactor = abs(aBalanceNode->heightLeft - aBalanceNode->heightRight);
		if (bFactor > 1)
		{
			balanceTree(aBalanceNode, bBalanceNode, cBalanceNode, root);
			fixTree(addedNode, root);
			break;
		}
		cBalanceNode = bBalanceNode;
		bBalanceNode = aBalanceNode;
		aBalanceNode = aBalanceNode->parent;
	}
}

bool AVLTree::add(string key, string data)
{
	auto newNode = new Node{ key, data, nullptr, nullptr, nullptr, 0, 0 };
	if (root == nullptr)
	{
		root = newNode;
		++size;
		return true;
	}

	auto current = root;
	Node *currentParent = nullptr;
	while (current != nullptr)
	{
		currentParent = current;

		if (key == current->key)
		{
			delete newNode;
			current->data = data;
			return false;
		}

		if (key < current->key)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	newNode->parent = currentParent;
	if (data < currentParent->data)
	{
		currentParent->left = newNode;
	}
	else
	{
		currentParent->right = newNode;
	}

	++size;
	fixTree(newNode, &root);
	return true;
}

string AVLTree::find(string key) const
{
	Node *current = root;
	while (current != nullptr)
	{
		if (key == current->key)
		{
			return current->data;
		}

		if (key < current->key)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	return "";
}

bool AVLTree::erase(string key)
{
	Node *current = root;
	while (current != nullptr)
	{
		if (key == current->key)
		{
			break;
		}

		if (key < current->key)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	if (current == nullptr)
	{
		return false;
	}

	Node *successorNode = nullptr;
	if (current->left == nullptr || current->right == nullptr)
	{
		successorNode = current;
	}
	else
	{
		successorNode = current->left;
		while (successorNode->right != nullptr)
		{
			successorNode = successorNode->right;
		}
	}

	Node *childOfSuccessorNode = nullptr;
	if (successorNode->right != nullptr)
	{
		childOfSuccessorNode = successorNode->right;
	}
	else
	{
		childOfSuccessorNode = successorNode->left;
	}
	if (childOfSuccessorNode != nullptr)
	{
		childOfSuccessorNode->parent = successorNode->parent;
	}

	if (successorNode->parent != nullptr)
	{
		if (successorNode == successorNode->parent->left)
		{
			successorNode->parent->left = childOfSuccessorNode;
		}
		else
		{
			successorNode->parent->right = childOfSuccessorNode;
		}
	}
	else
	{
		root = childOfSuccessorNode;
	}

	if (successorNode != current)
	{
		current->key = successorNode->key;
		current->data = successorNode->data;
	}

	--size;
	Node *fixingNode = successorNode->parent;
	delete successorNode;
	fixTree(fixingNode, &root);
	return true;
}

bool AVLTree::checkIfExist(string key) const
{
	Node *current = root;
	while (current != nullptr)
	{
		if (key == current->key)
		{
			return true;
		}

		if (key < current->key)
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	return false;
}


void deleteTree(Node *currentNode)
{
	if (currentNode == nullptr)
	{
		return;
	}

	deleteTree(currentNode->left);
	deleteTree(currentNode->right);

	delete currentNode;
}


void AVLTree::deleteAll()
{
	deleteTree(root);
	root = nullptr;
}