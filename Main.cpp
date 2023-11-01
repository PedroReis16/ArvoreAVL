// ArvoreAVL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.hpp"
#include "TreeInfos.hpp"
#include <random>
#include <chrono>

std::vector<int> generalList;

static void getRandomNumbers() {
	std::vector<int> saida;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<>intDistribution(0, 10000);

	for (int i = 0; i < 5000; i++) {
		int numero = intDistribution(gen);
		generalList.push_back(numero);
	}
}

TreeInfos* actions(int size) {

	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;
	TreeInfos* info = new TreeInfos();
	BinaryTree* tree = new BinaryTree();
	std::string description;

	if (size == 1000)
		description = "1000 elementos";
	else if (size == 3000)
		description = "3000 elementos";
	else
		description = "5000 elementos";

	info->Description = description;

	start = std::chrono::steady_clock::now();
	for (int i = 0; i < size; i++) {
		tree->insert(generalList[i]);
	}
	end = std::chrono::steady_clock::now();

	info->InsertionTime = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
	info->Depth = tree->getTreeDepth();

	std::vector<std::string> inOrder = tree->getInOrder();
	std::vector<std::string> preOrder = tree->getInPreOrder();
	std::vector<std::string> posOrder = tree->getInPostOrder();

	std::cout << "Lendo em ordem" << std::endl;
	std::cout << std::endl;
	start = std::chrono::steady_clock::now();
	for (int i = 0; i < inOrder.size(); i++) {
		std::cout << inOrder[i] << " ";
	}
	end = std::chrono::steady_clock::now();

	info->ReadInOrder = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();


	std::cout << std::endl;
	std::cout << "Lendo em pre-ordem" << std::endl;

	start = std::chrono::steady_clock::now();
	for (int i = 0; i < preOrder.size(); i++) {
		std::cout << preOrder[i] << " ";
	}
	end = std::chrono::steady_clock::now();

	info->ReadPreOrder = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	std::cout << std::endl;
	std::cout << "Lendo em pos-ordem" << std::endl;

	start = std::chrono::steady_clock::now();
	for (int i = 0; i < posOrder.size(); i++) {
		std::cout << posOrder[i] << " ";
	}
	end = std::chrono::steady_clock::now();

	info->ReadPosOrder = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();

	std::cout << std::endl;
	return info;
}

int main()
{
	getRandomNumbers();

	TreeInfos* AVL1Thousand = actions(1000);
	TreeInfos* AVL3Thousand = actions(3000);
	TreeInfos* AVL5Thousand = actions(5000);


	std::cout << std::endl;
	AVL1Thousand->getInfos();
	std::cout << std::endl;

	std::cout << std::endl;
	AVL3Thousand->getInfos();
	std::cout << std::endl;

	std::cout << std::endl;
	AVL5Thousand->getInfos();
	std::cout << std::endl;
}

