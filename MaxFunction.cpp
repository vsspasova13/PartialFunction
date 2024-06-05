#include "MaxFunction.h"

bool MaxFunction::isDefinedAt(int x)const
{
	for (int i = 0; i < this->getSize(); i++)
	{
		if (!functions[i]->isDefinedAt(x))return false;
	}
	return true;
}

Pair MaxFunction::compute(int x)const
{
	int max = functions[0]->compute(x).value;
	for (int i = 0; i < this->getSize(); i++)
	{
		if (!functions[i]->isDefinedAt(x))return Pair(0, 0);
		else if (functions[i]->compute(x).value > max)max = functions[i]->compute(x).value;
	}
	return Pair(1,max);
}

PartialFunction* MaxFunction::clone() const
{
	return new MaxFunction(*this);
}
