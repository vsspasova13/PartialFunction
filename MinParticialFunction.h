#pragma once
#include "ParticialFunctionOperation.h"

class MinParticialFunction:public ParticialFunctionOperation
{
public:
	MinParticialFunction(ParticialFunction**&& funct, uint16_t size);
	int32_t operator()(int32_t val)const override;
	ParticialFunction* clone()const override;
};

