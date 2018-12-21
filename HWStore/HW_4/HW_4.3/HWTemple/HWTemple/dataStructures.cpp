#include "pch.h"
#include <iostream>
#include <string.h>

#define BLACK 0
#define RED 1

//по большей части слизано с algolist
struct phoneNumberRecord
{
	char name[32];
	char phoneNumber[20];
};

struct Node
{
	phoneNumberRecord data;
	Node *left;
	Node *right;
	Node *parent;
	int color;
};

Node *leaf = new Node{ phoneNumberRecord{}, leaf, leaf, nullptr, BLACK };

#define LEAF leaf

struct BlackRedTree
{
	Node *root = LEAF;
	int size = 0;
};


void rotateLeft(BlackRedTree *tree, Node *rotatingNode)
{
	Node *rightSubTree = rotatingNode->right;

	rotatingNode->right = rightSubTree->left;
	if (rightSubTree->left != LEAF)
	{
		rightSubTree->left->parent = rotatingNode;
	}

	if (rightSubTree != LEAF)
	{
		rightSubTree->parent = rotatingNode->parent;
	}

	if (rotatingNode->parent != nullptr)
	{
		if (rotatingNode == rotatingNode->parent->left)
		{
			rotatingNode->parent->left = rightSubTree;
		}
		else
		{
			rotatingNode->parent->right = rightSubTree;
		}
	}
	else
	{
		tree->root = rightSubTree;
	}

	rightSubTree->left = rotatingNode;
	if (rotatingNode != LEAF)
	{
		rotatingNode->parent = rightSubTree;
	}
}

void rotateRight(BlackRedTree *tree, Node *rotatingNode)
{
	Node *leftSubTree = rotatingNode->left;

	rotatingNode->left = leftSubTree->right;
	if (leftSubTree->right != LEAF)
	{
		leftSubTree->right->parent = rotatingNode;
	}

	if (leftSubTree != LEAF)
	{
		leftSubTree->parent = rotatingNode->parent;
	}

	if (rotatingNode->parent != nullptr)
	{
		if (rotatingNode == rotatingNode->parent->right)
		{
			rotatingNode->parent->right = leftSubTree;
		}
		else
		{
			rotatingNode->parent->left = leftSubTree;
		}
	}
	else
	{
		tree->root = leftSubTree;
	}

	leftSubTree->right = rotatingNode;
	if (rotatingNode != LEAF)
	{
		rotatingNode->parent = leftSubTree;
	}
}


void insertFixup(BlackRedTree *tree ,Node *checkingNode)
{
	while (checkingNode != tree->root && checkingNode->parent->color == RED)
	{
		if (checkingNode->parent == checkingNode->parent->parent->left)
		{
			Node *uncleNode = checkingNode->parent->parent->right;
			if (uncleNode->color == RED)
			{
				checkingNode->parent->color = BLACK;
				uncleNode->color = BLACK;
				checkingNode->parent->parent->color = RED;
				checkingNode = checkingNode->parent->parent;
			}
			else
			{
				if (checkingNode == checkingNode->parent->right)
				{
					checkingNode = checkingNode->parent;
					rotateLeft(tree, checkingNode);
				}

				checkingNode->parent->color = BLACK;
				checkingNode->parent->parent->color = RED;
				rotateRight(tree, checkingNode->parent->parent);
			}
		}
		else
		{
			Node *uncleNode = checkingNode->parent->parent->left;
			if (uncleNode->color == RED)
			{
				checkingNode->parent->color = BLACK;
				uncleNode->color = BLACK;
				checkingNode->parent->parent->color = RED;
				checkingNode = checkingNode->parent->parent;
			}
			else
			{
				if (checkingNode == checkingNode->parent->left)
				{
					checkingNode = checkingNode->parent;
					rotateRight(tree, checkingNode);
				}

				checkingNode->parent->color = BLACK;
				checkingNode->parent->parent->color = RED;
				rotateLeft(tree, checkingNode->parent->parent);
			}
		}
	}
	tree->root->color = BLACK;
}



Node *insertNode(BlackRedTree *insertingTree, phoneNumberRecord *data, 
						bool (*compareIfLessOrEqual)(phoneNumberRecord, phoneNumberRecord))
{
	Node *current = insertingTree->root;
	Node *parent = nullptr;
	while (current != LEAF)
	{
		parent = current;
		if (compareIfLessOrEqual((*data), current->data))
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}

	Node *insertingNode = new Node{ *data, LEAF, LEAF, parent, RED };

	if (parent != nullptr)
	{
		if (compareIfLessOrEqual((*data), parent->data))
		{
			parent->left = insertingNode;
		}
		else
		{
			parent->right = insertingNode;
		}
	}
	else
	{
		insertingTree->root = insertingNode;
	}

	insertingTree->size++;
	insertFixup(insertingTree, insertingNode);
	return insertingNode;
}

void deleteFixup(BlackRedTree *tree, Node *checkingNode)
{
	while (checkingNode != tree->root && checkingNode->color == BLACK)
	{
		if (checkingNode == checkingNode->parent->left)
		{
			Node *uncleNode = checkingNode->parent->right;
			if (uncleNode->color == RED)
			{
				uncleNode->color = BLACK;
				checkingNode->parent->color = RED;
				rotateLeft(tree, checkingNode->parent);
				uncleNode = checkingNode->parent->right;
			}

			if (uncleNode->left->color == BLACK && uncleNode->right->color == BLACK)
			{
				uncleNode->color = RED;
				checkingNode = checkingNode->parent;
			}
			else
			{
				if (uncleNode->right->color == BLACK)
				{
					uncleNode->left->color = BLACK;
					uncleNode->color = RED;
					rotateRight(tree, uncleNode);
					uncleNode = checkingNode->parent->right;
				}

				uncleNode->color = checkingNode->parent->color;
				checkingNode->parent->color = BLACK;
				uncleNode->right->color = BLACK;
				rotateLeft(tree, checkingNode->parent);
				checkingNode = tree->root;
			}
		}
		else
		{
			Node *uncleNode = checkingNode->parent->left;
			
			if (uncleNode->color == RED)
			{
				uncleNode->color = BLACK;
				checkingNode->parent->color = RED;
				rotateRight(tree, checkingNode->parent);
				uncleNode = checkingNode->parent->left;
			}

			if (uncleNode->right->color == BLACK && uncleNode->left->color == BLACK)
			{
				uncleNode->color = RED;
				checkingNode = checkingNode->parent;
			}
			else
			{
				if (uncleNode->left->color == BLACK)
				{
					uncleNode->right->color = BLACK;
					uncleNode->color = RED;
					rotateLeft(tree, uncleNode);
					uncleNode = checkingNode->parent->left;
				}

				uncleNode->color = checkingNode->parent->color;
				checkingNode->parent->color = BLACK;
				uncleNode->left->color = BLACK;
				rotateRight(tree, checkingNode->parent);
				checkingNode = tree->root;
			}
		}
	}
	checkingNode->color = BLACK;
}

void deleteNode(BlackRedTree *tree, Node *deletingNode)
{
	Node *successorNode = nullptr;
	Node *childOfSuccessorNode = nullptr;

	if (deletingNode == LEAF || deleteNode == nullptr)
	{
		printf("Неверный указатель для удаления\n");
		return;
	}

	if (deletingNode->left == LEAF || deletingNode->right == LEAF)
	{
		successorNode = deletingNode;
	}
	else
	{
		successorNode = deletingNode->left;
		while (successorNode->right != LEAF)
		{
			successorNode = successorNode->right;
		}
	}

	if (successorNode->right != LEAF)
	{
		childOfSuccessorNode = successorNode->right;
	}
	else
	{
		childOfSuccessorNode = successorNode->left;
	}

	
	childOfSuccessorNode->parent = successorNode->parent;

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
		tree->root = childOfSuccessorNode;
	}

	if (successorNode != deletingNode)
	{
		deletingNode->data = successorNode->data;
	}

	if (successorNode->color == BLACK && childOfSuccessorNode != nullptr)
	{
		deleteFixup(tree, childOfSuccessorNode);
	}

	tree->size--;
	delete successorNode;
}

void printAllEqual(Node *leftBorderNode, Node *rightBorderNode, phoneNumberRecord *data,
					bool(*compareIfEqual)(phoneNumberRecord, phoneNumberRecord),
						bool(*printData)(phoneNumberRecord),
							Node *currentNode = nullptr)
{
	if (currentNode == nullptr)
	{
		currentNode = rightBorderNode;
	}

	if (currentNode->left != LEAF && currentNode != leftBorderNode)
	{
		printAllEqual(leftBorderNode, rightBorderNode, data, compareIfEqual, printData, currentNode->left);
	}

	if (compareIfEqual(*data, currentNode->data))
	{
		printData(currentNode->data);
	}

	if (currentNode->right != LEAF && currentNode != rightBorderNode)
	{
		printAllEqual(leftBorderNode, rightBorderNode, data, compareIfEqual, printData, currentNode->right);
	}
}

Node *findData(BlackRedTree *tree, phoneNumberRecord *data,
				bool(*compareIfEqual)(phoneNumberRecord, phoneNumberRecord),
					bool(*compareIfLessOrEqual)(phoneNumberRecord, phoneNumberRecord),
						bool(*printData)(phoneNumberRecord) = nullptr)
{
	Node *current = tree->root;
	while (current != LEAF)
	{
		if (compareIfEqual(*data, current->data))
		{
			if (printData != nullptr)
			{
				Node *leftBorderNode = current;
				while (leftBorderNode->left != LEAF)
				{
					leftBorderNode = leftBorderNode->left;
					if (compareIfEqual(*data, current->data))
					{
						break;
					}
				}
				printAllEqual(leftBorderNode, current, data, compareIfEqual, printData);
			}

			break;
		}

		if (compareIfLessOrEqual(*data, current->data))
		{
			current = current->left;
		}
		else
		{
			current = current->right;
		}
	}
	return current;
}

void printAllData(BlackRedTree *tree, Node *currentNode = nullptr, FILE *outputFile = nullptr)
{
	if (currentNode == nullptr)
	{
		currentNode = tree->root;
	}

	if (currentNode->left != LEAF)
	{
		printAllData(tree, currentNode->left, outputFile);
	}

	if (outputFile == nullptr)
	{
		printf("Имя: %s\tНомер: %s\n", currentNode->data.name, currentNode->data.phoneNumber);
	}
	else
	{
		fprintf(outputFile, "Имя: %s, Телефонный номер: %s\n", currentNode->data.name, currentNode->data.phoneNumber);
	}

	if (currentNode->right != LEAF)
	{
		printAllData(tree, currentNode->right, outputFile);
	}
}

void deleteAllData(BlackRedTree *tree, Node *currentNode = nullptr)
{
	if (currentNode == nullptr)
	{
		currentNode = tree->root;
	}

	if (currentNode->left != LEAF)
	{
		deleteAllData(tree, currentNode->left);
	}

	if (currentNode->right != LEAF)
	{
		deleteAllData(tree, currentNode->right);
	}

	tree->size--;
	delete currentNode;
}