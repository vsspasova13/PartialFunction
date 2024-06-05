#include "FunctObjModeOne.h"

Pair FunctObjModeOne::operator()(int x) const
{
	for (size_t i = 0; i < size; i++)
	{
		if (arr[i] == x)
		{
			return Pair(0, 0);
		}
	}
	return Pair(1,x);
}

FunctObj* FunctObjModeOne::clone() const
{
	return new FunctObjModeOne(*this);
}
