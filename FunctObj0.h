#pragma once
#include "FunctObj.h"
class FunctObj0: public FunctObj
{
public:
	Pair operator()(int)const override;
	FunctObj* clone() const override;
	FunctObj0(const int* arr, size_t size) :FunctObj(arr, size) {};
};

