#include "TypeZeroFunction.h"

TypeZeroFunction::TypeZeroFunction(uint16_t size, std::ifstream& ifs):size(size),arg(size),val(size)
{
    arg.readFromFile(ifs, size);
    val.readFromFile(ifs, size);
}

Pair TypeZeroFunction::operator()(int32_t value) const
{
    int ind = -1;
    for (size_t i = 0; i < size; i++)
    {
        if (arg[i] == value)
        {
            ind = i;
            break;
        }
    }
    if (ind == -1)
        return Pair{ false, 0};
    else 
        return Pair{ true, val[ind] };
}
