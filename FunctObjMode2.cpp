#include "FunctObjMode2.h"

Pair FunctObjMode2::operator()(int x) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == x)
			return Pair(1, 1);
	}
	return Pair(1, 0);
}

FunctObj* FunctObjMode2::clone() const
{
	return new FunctObjMode2(*this);
}
