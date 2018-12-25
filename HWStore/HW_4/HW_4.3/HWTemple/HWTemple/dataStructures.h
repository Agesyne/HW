#pragma once

#define BLACK 0
#define RED 1
#define LEAF leaf

struct PhoneNumberRecord
{
	char name[32];
	char phoneNumber[20];
};

struct Node
{
	PhoneNumberRecord data;
	Node *left;
	Node *right;
	Node *parent;
	int color;
};

extern Node *leaf;

struct BlackRedTree
{
	Node *root = LEAF;
	int size = 0;
};

Node *insertNode(BlackRedTree *insertingTree, PhoneNumberRecord *data,
					bool(*compareIfLessOrEqual)(PhoneNumberRecord, PhoneNumberRecord));

void deleteNode(BlackRedTree *tree, Node *deletingNode);

Node *findData(BlackRedTree *tree, PhoneNumberRecord *data,
				bool(*compareIfEqual)(PhoneNumberRecord, PhoneNumberRecord),
					bool(*compareIfLessOrEqual)(PhoneNumberRecord, PhoneNumberRecord),
						bool(*printData)(PhoneNumberRecord));

void printAllData(BlackRedTree *tree, Node *currentNode = nullptr, FILE *outputFile = nullptr);

void deleteAllData(BlackRedTree *tree, Node *currentNode = nullptr);
