#pragma once
#include <string>
#include <iostream>

class TreeInfos
{
public:
	std::string Description;
	double InsertionTime;
	int Depth;
	int Height;
	int ReadInOrder;
	int ReadPreOrder;
	int ReadPosOrder;
	void getInfos();
};

