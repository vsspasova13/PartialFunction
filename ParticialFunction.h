#pragma once
#include <iostream>
#include <cstdint>

class ParticialFunction
{
public:
	ParticialFunction() = default;
	virtual bool isDefined(int32_t x)const = 0;
	virtual int32_t operator()(int32_t value)const = 0;
	virtual ParticialFunction* clone()const = 0;
	virtual ~ParticialFunction() = default;
};

