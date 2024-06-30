#pragma once
#include <fstream>
#include "MyVector.h"
#include "Pair.h"

class TypeTwoFunction
{
	MyVector nums;
	uint16_t size = 0;
public:
	TypeTwoFunction(uint16_t size, std::ifstream& ifs);
	Pair operator()(int32_t val)const;
};

