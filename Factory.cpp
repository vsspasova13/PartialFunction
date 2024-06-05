#pragma once
#include "Factory.h"
#include "ReadFromFile.h"

PartialFunction* Factory::FunctionByValues(const int* values, size_t size) const
{
	FunctObj* obj = new FunctObj0(values, size);
	return new CriteriaPartialFunction<FunctObj>(obj);
}

PartialFunction* Factory::FunctionByDefinedValues(const int* values, size_t size) const
{
	FunctObj* obj = new FunctObjModeOne(values, size);
	return new CriteriaPartialFunction<FunctObj>(obj);
}

PartialFunction* Factory::FunctionByValuesZerosAndOnes(const int* values, size_t size) const
{
	FunctObj* obj = new FunctObjMode2(values, size);
	return new CriteriaPartialFunction<FunctObj>(obj);
}

MaxFunction* Factory::MaxFunc(Vector<MyString> vect, size_t size) const
{
	MaxFunction* collection=new MaxFunction();
	for (size_t i = 0; i < size; i++)
	{
		ReadFromFile h(vect[i]);
		collection->addFunction(h.handleCase());
	}
	return collection;
}

MinFunction* Factory::MinFunc(Vector<MyString> vect, size_t size) const
{
	MinFunction* collection = new MinFunction();
	for (size_t i = 0; i < size; i++)
	{
		ReadFromFile h(vect[i]);
		collection->addFunction(h.handleCase());
	}
	return collection;
}
