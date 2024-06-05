#pragma once
#include "PartialFunction.h"
class FunctionCollection :public PartialFunction
{
protected:
	PartialFunction** functions;
private:
	size_t size;
	size_t capacity;

	void free();
	void copyFrom(const FunctionCollection& other);
	void moveFrom(FunctionCollection&& other);
	void resize(size_t size);

public:
	FunctionCollection();
	FunctionCollection(size_t capacity);
	FunctionCollection(const FunctionCollection& other);
	FunctionCollection& operator=(const FunctionCollection& other);
	FunctionCollection(FunctionCollection&& other)noexcept;
	FunctionCollection& operator=(FunctionCollection&& other)noexcept;
	~FunctionCollection();

	void addFunction(PartialFunction* func);
	size_t getSize()const;

	const PartialFunction* operator[](int ind)const;

};



