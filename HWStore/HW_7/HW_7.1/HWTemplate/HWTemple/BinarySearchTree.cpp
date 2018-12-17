#include "pch.h"
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node *parent;
	Node *left;
	Node *right;
};

BinarySearchTree::BinarySearchTree()
{
}


BinarySearchTree::~BinarySearchTree()
{
	deleteAll();
}

bool BinarySearchTree::add(const int data)
{
	auto newNode = new Node{ data, nullptr, nullptr, nullptr };
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

		if (data == current->data)
		{
			delete newNode;
			return false;
		}

		if (data < current->data)
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
	return true;
}

bool BinarySearchTree::find(const int data) const
{
	Node *current = root;
	while (current != nullptr)
	{
		if (data == current->data)
		{
			return true;
		}

		if (data < current->data)
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

bool BinarySearchTree::erase(const int data)
{
	Node *current = root;
	while (current != nullptr)
	{
		if (data == current->data)
		{
			break;
		}

		if (data < current->data)
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
		current->data = successorNode->data;
	}

	--size;
	delete successorNode;
	return true;
}

void BinarySearchTree::printAll(const bool isStraightOrder, Node *currentNode) const
{
	static int counter = -1;
	if (counter == -1 && currentNode == nullptr)
	{
		currentNode = root;
		++counter;
	}

	if (currentNode == nullptr)
	{
		return;
	}

	if (isStraightOrder)
	{
		printAll(isStraightOrder, currentNode->left);
	}
	else
	{
		printAll(isStraightOrder, currentNode->right);
	}

	cout << "(" << currentNode->data << ")->";

	if (isStraightOrder)
	{
		printAll(isStraightOrder, currentNode->right);
	}
	else
	{
		printAll(isStraightOrder, currentNode->left);
	}

	++counter;
	if (counter == size)
	{
		counter = -1;
		cout << "[]" << endl;
	}
}

void BinarySearchTree::deleteAll(Node *currentNode)
{
	static int counter = -1;
	if (counter == -1 && currentNode == nullptr)
	{
		currentNode = root;
		if (root == nullptr)
		{
			return;
		}
		++counter;
	}

	if (currentNode == nullptr)
	{
		return;
	}

	deleteAll(currentNode->left);
	deleteAll(currentNode->right);

	delete currentNode;

	++counter;
	if (counter == size)
	{
		counter = -1;
		size = 0;
	}
}