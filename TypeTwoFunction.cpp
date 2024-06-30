#include "TypeTwoFunction.h"

TypeTwoFunction::TypeTwoFunction(uint16_t size, std::ifstream& ifs):nums(size),size(size)
{
    nums.readFromFile(ifs, size);
}

Pair TypeTwoFunction::operator()(int32_t val) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (nums[i] == val)
		{
			return Pair{ true, 1 };
		}
	}
	return Pair{ true,0 };
}
