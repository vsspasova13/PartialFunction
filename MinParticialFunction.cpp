#include "MinParticialFunction.h"

MinParticialFunction::MinParticialFunction(ParticialFunction**&& funct, uint16_t size):ParticialFunctionOperation(std::move(funct),size)
{
}

int32_t MinParticialFunction::operator()(int32_t val) const
{
    int32_t min = (*(functions[0]))(val);
    int32_t curr;
    for (size_t i = 1; i < size; i++)
    {
        curr = (*(functions[i]))(val);
        if (curr < min)
        {
            min = curr;
        }
            
    }
    return min;
}

ParticialFunction* MinParticialFunction::clone() const
{
    return new MinParticialFunction(*this);
}
