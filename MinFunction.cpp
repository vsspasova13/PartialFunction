#include "MinFunction.h"
bool MinFunction::isDefinedAt(int x)const
{

	for (int i = 0; i < this->getSize(); i++)
	{
		if (!functions[i]->isDefinedAt(x))return false;
	}
	return true;
}

Pair MinFunction::compute(int x)const
{
	int min = functions[0]->compute(x).value;
	for (int i = 0; i < this->getSize(); i++)
	{
		if (!functions[i]->isDefinedAt(x))return Pair(0, 0);
		else if (functions[i]->compute(x).value <min)min = functions[i]->compute(x).value;
	}
	return Pair(1, min);

}

PartialFunction* MinFunction::clone() const
{
	return new MinFunction(*this);
}
