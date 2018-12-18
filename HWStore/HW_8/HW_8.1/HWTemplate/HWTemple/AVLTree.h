#pragma once
#include <string>

extern struct Node;

class AVLTree
{
private:
	Node *root = nullptr;
	int size = 0;
public:
	AVLTree();
	~AVLTree();

	bool add(std::string key, std::string data);

	std::string find(std::string key) const;

	bool erase(std::string key);

	bool checkIfExist(std::string key) const;
};

