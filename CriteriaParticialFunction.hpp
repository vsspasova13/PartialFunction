#include "ParticialFunction.h"
#include "Pair.h"

template<class T>
class CriteriaParticialFunction:public ParticialFunction
{
	T funct;
public:
	CriteriaParticialFunction(const T& funct);
	bool isDefined(int32_t value)const override;
	ParticialFunction* clone()const override;
	int32_t operator()(int32_t value)const override;
	//const Pair& compute(int32_t value)const;
};

template<class T>
CriteriaParticialFunction<T>::CriteriaParticialFunction(const T& funct):funct(funct)
{
}

template<class T>
bool CriteriaParticialFunction<T>::isDefined(int32_t value) const
{
	return funct(value).isDefined;
}

template<class T>
ParticialFunction* CriteriaParticialFunction<T>::clone() const
{
	return new CriteriaParticialFunction(*this);
}

template<class T>
int32_t CriteriaParticialFunction<T>::operator()(int32_t value) const
{
	return funct(value).res;
}
