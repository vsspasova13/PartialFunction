#include "ParticialFunctionOperation.h"

void ParticialFunctionOperation::free()
{
    for (size_t i = 0; i < size; i++)
    {
        delete functions[i];
        functions[i] = nullptr;
    }
    delete[]functions;
    functions = nullptr;
    size = 0;
}

void ParticialFunctionOperation::copyFrom(const ParticialFunctionOperation& other)
{
    functions = new ParticialFunction * [other.size];
    for (size_t i = 0; i < size; i++)
    {
        functions[i] = other.functions[i]->clone();
    }
    size = other.size;

}

void ParticialFunctionOperation::moveFrom(ParticialFunctionOperation&& other)
{
    functions = other.functions;
    size = other.size;
    other.functions = nullptr;
    other.size = 0;
}

ParticialFunctionOperation::ParticialFunctionOperation(ParticialFunction**&& functions, uint16_t size)
{
    if (size == 0 || !functions)
        return;
    this->functions = new ParticialFunction * [size] {nullptr};
    for (size_t i = 0; i < size; i++)
    {
        if (!functions[i])
        {
            free();
            throw std::invalid_argument("No existing function.");
        }
        this->functions[i] = functions[i];
        functions[i] = nullptr;
    }
}

ParticialFunctionOperation::ParticialFunctionOperation(const ParticialFunctionOperation& other)
{
    copyFrom(other);
}

ParticialFunctionOperation& ParticialFunctionOperation::operator=(const ParticialFunctionOperation& other)
{
    if (this != &other)
    {
        free();
        copyFrom(other);
   }
    return *this;
}

ParticialFunctionOperation::ParticialFunctionOperation(ParticialFunctionOperation&& other) noexcept
{
    moveFrom(std::move(other));
}

ParticialFunctionOperation& ParticialFunctionOperation::operator=(ParticialFunctionOperation&& other) noexcept
{
    if (this != &other)
    {
        free();
        moveFrom(std::move(other));
    }
    return *this;
}

ParticialFunctionOperation::~ParticialFunctionOperation() noexcept
{
    free();
}

bool ParticialFunctionOperation::isDefined(int32_t val) const
{
    for (size_t i = 0; i < size; i++)
    {
        if (!functions[i]->isDefined(val))
            return false;
    }
    return true;
}
