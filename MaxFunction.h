#include "FunctionCollection.h"
#include "PartialFunction.h"
#include <iostream>

class MaxFunction :public FunctionCollection
{
public:
	MaxFunction() :FunctionCollection() {  };
	bool isDefinedAt(int x)const override;
	Pair compute(int x)const override;
	PartialFunction* clone() const;
};




