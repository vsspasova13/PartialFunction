#include "TypeOneFunction.h"

TypeOneFunction::TypeOneFunction(uint16_t size, std::ifstream& ifs):defined(size),size(size)
{
    defined.readFromFile(ifs, size);
}

Pair TypeOneFunction::operator()(int32_t val) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (defined[i] == val) 
		{
			return Pair{ false,0 };
		}
	}
	return Pair{ true,val };
}
