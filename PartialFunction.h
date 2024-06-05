#pragma once
#include <iostream>
#include "Pair.h"

class PartialFunction
{
public:
	virtual bool isDefinedAt(int x)const = 0;
	virtual Pair compute(int x)const = 0;
	virtual PartialFunction* clone() const = 0;
	virtual ~PartialFunction() = default;

};