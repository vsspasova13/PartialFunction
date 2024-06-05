#include "FunctObj0.h"

Pair FunctObj0::operator()(int x) const
{
	for (size_t i = 0; i < size/2; i++)
	{
		if (arr[i] == x)
			return Pair(true, arr[i + size / 2]);
		
	}
	return Pair(false, 0);
}

FunctObj* FunctObj0::clone() const
{
	return new FunctObj0(*this);
}
