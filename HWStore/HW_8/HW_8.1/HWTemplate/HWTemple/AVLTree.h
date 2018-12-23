#pragma once
#include <string>

struct Node;

class AVLTree
{
private:
	Node *root = nullptr;
	int size = 0;
public:
	AVLTree();
	~AVLTree();

	bool add(const std::string data, const std::string key = "");

	std::string find(const std::string key) const;

	bool erase(const std::string key);

	bool checkIfExist(const std::string key) const;

	void deleteAll();

	void printAll(const std::string &text);
};

