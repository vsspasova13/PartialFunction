#pragma once
#include <fstream>
#include "MyVector.h"
#include "Pair.h"

class TypeOneFunction
{
	MyVector defined;
	uint16_t size = 0;

public:
	TypeOneFunction(uint16_t size, std::ifstream& ifs);
	Pair operator()(int32_t val)const;
};

