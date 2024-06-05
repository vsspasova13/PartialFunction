#pragma once
#include "FunctObj.h"
class FunctObjModeOne:public FunctObj
{
public:
	Pair operator()(int)const override;
	FunctObj* clone() const override;
	FunctObjModeOne(const int* arr, size_t size):FunctObj(arr, size) {};
};

