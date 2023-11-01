// ArvoreAVL.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "BinaryTree.hpp"
#include <random>
#include <chrono>

static std::vector<int> getRandomNumbers() {
	std::vector<int> saida;
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<>intDistribution(1, 1000000);

	for (int i = 0; i < 5000; i++) {
		int numero = intDistribution(gen);
		saida.push_back(numero);
	}

	return saida;
}
int main()
{
	BinaryTree AVL;

	std::vector<int> numbers = getRandomNumbers();
}

