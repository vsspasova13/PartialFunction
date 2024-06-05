#pragma once
#include "Pair.h"

class FunctObj
{
protected:
	int* arr;
	size_t size;
public:
	virtual Pair operator()(int)const =0;
	virtual FunctObj* clone() const = 0;
	FunctObj(const int* arr, size_t size);

};

