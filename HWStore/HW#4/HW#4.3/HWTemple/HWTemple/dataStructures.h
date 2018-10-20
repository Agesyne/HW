#pragma once

#define BLACK 0
#define RED 1

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

extern Node *leaf;

#define LEAF leaf

struct BlackRedTree
{
	Node *root = LEAF;
	int size = 0;
};

Node *insertNode(BlackRedTree *insertingTree, phoneNumberRecord *data,
					bool(*compareIfLessOrEqual)(phoneNumberRecord, phoneNumberRecord));

void deleteNode(BlackRedTree *tree, Node *deletingNode);

Node *findData(BlackRedTree *tree, phoneNumberRecord *data,
				bool(*compareIfEqual)(phoneNumberRecord, phoneNumberRecord),
					bool(*compareIfLessOrEqual)(phoneNumberRecord, phoneNumberRecord),
						bool(*printData)(phoneNumberRecord));

void printAllData(BlackRedTree *tree, Node *currentNode = nullptr, FILE *outputFile = nullptr);

void deletetAllData(BlackRedTree *tree, Node *currentNode = nullptr);
