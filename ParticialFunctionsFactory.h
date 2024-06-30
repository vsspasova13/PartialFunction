#pragma once
#include "ParticialFunction.h"
#include <fstream>

class ParticialFunctionsFactory
{
public:
	static ParticialFunction* create(const char* fileName);
	static ParticialFunction* create(std::ifstream& ifs);
	static ParticialFunction** createArr(std::ifstream& ifs, uint16_t size);

};

