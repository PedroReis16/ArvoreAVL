#pragma once
#include "Node.hpp"
#include <string>
#include <vector>

class BinaryTree
{

private:
	Node* root;
	std::vector<std::string> readVector;
	void updateHeight(Node* node);
	int getBalanceFactor(Node* node);
	Node* rotateRight(Node* y);
	Node* rotateLeft(Node* x);
	Node* balance(Node* node);
	void insert(Node* node, int value);
	int getHeight(Node* node);
	int getTreeDepth(Node* node);
	void inOrder(Node* node, int level);
	void preOrder(Node* node, int level);
	void postOrder(Node* node, int level);

public:
	BinaryTree();
	void insert(int value);
	int getTreeDepth();
	std::vector<std::string> getInOrder();
	std::vector<std::string> getInPreOrder();
	std::vector<std::string> getInPostOrder();
};

