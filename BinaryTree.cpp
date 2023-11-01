#include "BinaryTree.hpp"
#include <algorithm>
#include <iostream>
#include <stack>

BinaryTree::BinaryTree() :root(nullptr) {}

int BinaryTree::getHeight(Node* node) {
	if (node == nullptr) return 0;
	return node->height;
}
void BinaryTree::updateHeight(Node* node) {
	if (node != nullptr) {
		node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
	}
}
int BinaryTree::getBalanceFactor(Node* node) {
	if (node == nullptr)
		return 0;
	return node->height;
}
Node* BinaryTree::rotateRight(Node* y) {
	if (y == nullptr || y->left == nullptr) {
		return y;
	}

	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left = T2;

	updateHeight(y);
	updateHeight(x);

	return x;
}
Node* BinaryTree::rotateLeft(Node* x) {
	if (x == nullptr || x->right == nullptr) {
		return x;
	}

	Node* y = x->right;
	Node* T2 = y->left;

	y->left = x;
	x->right = T2;

	updateHeight(x);
	updateHeight(y);

	return y;
}
Node* BinaryTree::balance(Node* node) {

	updateHeight(node);
	int balance = getHeight(node->left) - getHeight(node->right);

	if (balance > 1) {
		if (getHeight(node->left->left) >= getHeight(node->left->right)) {
			return rotateRight(node);
		}
		else {
			node->left = rotateLeft(node->left);
			return rotateRight(node);
		}
	}

	if (balance < -1) {
		if (getHeight(node->right->right) >= getHeight(node->right->left)) {
			return rotateLeft(node);
		}
		else {
			node->right = rotateRight(node->right);
			return rotateLeft(node);
		}
	}
	return node;
}
void BinaryTree::insert(Node* node, int value) {
	Node* newNode = new Node(value);
	if (root == nullptr) {
		root = newNode;
		return;
	}

	std::stack<Node*> nodeStack;
	Node* current = root;

	while (current != nullptr) {
		nodeStack.push(current);
		if (value < current->value) {
			current = current->left;
		}
		else if (value > current->value) {
			current = current->right;
		}
		else {
			delete newNode;
			return;
		}
	}

	current = nodeStack.top();
	if (value < current->value) {
		current->left = newNode;
	}
	else {
		current->right = newNode;
	}

	while (!nodeStack.empty()) {
		current = nodeStack.top();
		nodeStack.pop();
		current = balance(current);

		if (!nodeStack.empty()) {
			Node* parent = nodeStack.top();
			if (current->value < parent->value) {
				parent->left = current;
			}
			else {
				parent->right = current;
			}
		}
		else {
			root = current;
		}
	}
}
void BinaryTree::insert(int value) {
	insert(root, value);
}
int BinaryTree::getTreeDepth(Node* node) {
	if (node == nullptr) {
		return 0;
	}
	int leftDepth = getTreeDepth(node->left);
	int rightDepth = getTreeDepth(node->right);

	return 1 + std::max(leftDepth, rightDepth);
}
void BinaryTree::inOrder(Node* node, int level) {

	if (node != nullptr) {
		inOrder(node->left, level + 1);
		readVector.push_back(std::to_string(node->value) + "(" + std::to_string(level) + ")" + " ");
		inOrder(node->right, level + 1);
	}
}
void BinaryTree::preOrder(Node* node, int level) {
	if (node != nullptr) {
		readVector.push_back(std::to_string(node->value) + "(" + std::to_string(level) + ")" + " ");
		preOrder(node->left, level + 1);
		preOrder(node->right, level + 1);
	}
}
void BinaryTree::postOrder(Node* node, int level) {
	if (node != nullptr) {
		postOrder(node->left, level + 1);
		postOrder(node->right, level + 1);
		readVector.push_back(std::to_string(node->value) + "(" + std::to_string(level) + ")" + " ");
	}
}
int BinaryTree::getTreeDepth() {
	return getTreeDepth(root);
}
std::vector<std::string> BinaryTree::getInOrder() {
	readVector.clear();
	inOrder(root, 1);

	std::vector<std::string>list = readVector;
	return list;
}
std::vector<std::string> BinaryTree::getInPreOrder() {
	readVector.clear();
	preOrder(root, 1);

	std::vector<std::string>list = readVector;
	return list;
}
std::vector<std::string> BinaryTree::getInPostOrder() {
	readVector.clear();
	postOrder(root, 1);

	std::vector<std::string>list = readVector;
	return list;
}