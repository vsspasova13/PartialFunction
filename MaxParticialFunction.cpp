#include "MaxParticialFunction.h"

MaxParticialFunction::MaxParticialFunction(ParticialFunction**&& funct, uint16_t size):ParticialFunctionOperation(std::move(funct),size)
{
}

int32_t MaxParticialFunction::operator()(int32_t val) const
{
	int32_t max = (*(functions[0]))(val);
	int32_t curr;
	for (size_t i = 1; i < size; i++)
	{
		curr = (*(functions[i]))(val);
		if (curr > max)
		{
			max = curr;
		}
	}
	return max;
}

ParticialFunction* MaxParticialFunction::clone() const
{
	return new MaxParticialFunction(*this);
}
