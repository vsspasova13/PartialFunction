#pragma once
#include "FunctObj.h"

class FunctObjMode2:public FunctObj
{
public:
	Pair operator()(int)const override;
	FunctObj* clone() const override;
	FunctObjMode2(const int* arr, size_t size):FunctObj(arr, size) {};

};

