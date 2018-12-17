#pragma once

extern struct Node;

class BinarySearchTree
{
private:
	Node *root = nullptr;
	int size = 0;
public:
	BinarySearchTree();
	~BinarySearchTree();

	bool add(const int data);

	bool find(const int data) const;

	bool erase(const int data);

	void printAll(const bool isStraightOrder = true, Node *rootNode = nullptr) const;

	void deleteAll(Node *rootNode = nullptr);
};

