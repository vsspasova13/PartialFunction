#include "FunctionCollection.h"
#include <iostream>

class MinFunction :public FunctionCollection
{
public:
	MinFunction():FunctionCollection() {  };
	bool isDefinedAt(int x)const override;
	Pair compute(int x)const override;
	PartialFunction* clone() const;
};




