#include "BinaryTree.hpp"
#include <algorithm>
#include <iostream>

BinaryTree::BinaryTree() :root(nullptr) {}

int BinaryTree::getHeight(Node* node) {
	if (node == nullptr) return 0;
	return node->height;
}
int BinaryTree::getBalanceFactor(Node* node) {
	if (node == nullptr)
		return 0;
	return node->height;
}
void BinaryTree::updateHeight(Node* node) {
	if (node != nullptr) {
		node->height = 1 + std::max(getHeight(node->left), getHeight(node->right));
	}
}
Node* BinaryTree::rotateRight(Node* y) {
	Node* x = y->left;
	Node* T2 = x->right;

	x->right = y;
	y->left = T2;

	updateHeight(y);
	updateHeight(x);

	return x;
}
Node* BinaryTree::rotateLeft(Node* x) {
	Node* y = x->right;
	Node* T2 = y->left;

	y->left = x;
	x->right = T2;

	updateHeight(x);
	updateHeight(y);

	return y;
}
Node* BinaryTree::balance(Node* node, int value) {
	updateHeight(node);
	int balance = getBalanceFactor(node);

	if (balance > 1 && value < node->left->value) {
		return rotateRight(node);
	}

	if (balance < -1 && value > node->right->value) {
		return rotateLeft(node);
	}

	if (balance > 1 && value > node->left->value) {
		node->left = rotateLeft(node->left);
		return rotateRight(node);
	}

	if (balance < -1 && value < node->right->value) {
		node->right = rotateRight(node->right);
		return rotateLeft(node);
	}

	return node;
}
Node* BinaryTree::insert(Node* node, int value) {
	if (node == nullptr) {
		return new Node(value);
	}

	if (value < node->value) {
		node->left = insert(node->left, value);
	}
	else if (value > node->value) {
		node->right = insert(node->right, value);
	}
	else {
		return node; // Ignorar chaves duplicadas
	}

	return balance(node, value);
}
void BinaryTree::insert(int value) {
	root = insert(root, value);
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
		std::cout << node->value << "(" << level << ") ";
		inOrder(node->right, level + 1);
	}
}
void BinaryTree::preOrder(Node* node, int level) {
	if (node != nullptr) {
		std::cout << node->value << "(" << level << ") ";
		preOrder(node->left, level + 1);
		preOrder(node->right, level + 1);
	}
}
void BinaryTree::postOrder(Node* node, int level) {
	if (node != nullptr) {
		postOrder(node->left, level + 1);
		postOrder(node->right, level + 1);
		std::cout << node->value << "(" << level << ") ";
	}
}
int BinaryTree::getTreeDepth() {
	return getTreeDepth(root);
}
void BinaryTree::printInOrder() {
	inOrder(root, 1);
	std::cout << std::endl;
}
void BinaryTree::printPreOrder() {
	preOrder(root, 1);
	std::cout << std::endl;
}
void BinaryTree::printPostOrder() {
	postOrder(root, 1);
	std::cout << std::endl;
}