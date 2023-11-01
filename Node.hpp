#pragma once
class Node
{
public:
	Node(int value);
	Node* left;
	Node* right;
	int value;
	int height;
};

