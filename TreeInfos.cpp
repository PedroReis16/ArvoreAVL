#include "TreeInfos.hpp"

void TreeInfos::getInfos() {
	std::cout << "Descricao: " << Description << std::endl;
	std::cout << "Tempo de insercao: " << InsertionTime << " em milissegundos" << std::endl;
	std::cout << "Profundidade: " << Depth << std::endl;
	std::cout << "Altura: " << Height << std::endl;
}