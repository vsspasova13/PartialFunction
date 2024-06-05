#pragma once
#include "MinFunction.h"
#include "MaxFunction.h"
#include "CriteriaPartialFunction.hpp"
#include "Factory.h"
#include "FunctObj0.h"
#include "FunctObjModeOne.h"
#include "FunctObjMode2.h"
#include "Vector.hpp"
#include "MyString.h"

class Factory
{
public:
	PartialFunction* FunctionByValues(const int* values, size_t size)const;
	PartialFunction* FunctionByDefinedValues(const int* values, size_t size)const;
	PartialFunction* FunctionByValuesZerosAndOnes(const int* values, size_t size)const;
	MaxFunction* MaxFunc(Vector<MyString> vect, size_t size)const;
	MinFunction* MinFunc(Vector<MyString> vect, size_t size)const;


};

