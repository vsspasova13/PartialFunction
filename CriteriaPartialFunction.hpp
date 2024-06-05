#pragma once
#include "PartialFunction.h"
#include "Pair.h"

template <class T>
class CriteriaPartialFunction :public PartialFunction
{
	T* funct=nullptr;

public:
	CriteriaPartialFunction(T* func222);
	virtual bool isDefinedAt(int x)const override;
	virtual Pair compute(int x)const override;
	virtual PartialFunction* clone()const override;
};

template<class T>
CriteriaPartialFunction<T>::CriteriaPartialFunction(T* arg)
{
	funct = (*arg).clone();
}

template<class T>
bool CriteriaPartialFunction<T>::isDefinedAt(int x) const
{
	return (*funct)(x).isDefined;
}

template<class T>
Pair CriteriaPartialFunction<T>::compute(int x) const
{
	return (*funct)(x);
}

template<class T>
 PartialFunction* CriteriaPartialFunction<T>::clone() const
{
	return new CriteriaPartialFunction(*this);
}
