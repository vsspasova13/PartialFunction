#pragma once
#include "Pair.h"
#include "MyVector.h"
#include <fstream>

class TypeZeroFunction
{
	MyVector arg;
	MyVector val;
	uint16_t size=0;

public:
	TypeZeroFunction(uint16_t size, std::ifstream& ifs);
	Pair operator()(int32_t val)const;
};

