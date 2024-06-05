#include "FunctionCollection.h"

void FunctionCollection::free()
{
	for (int i = 0; i < size; i++)
	{
		delete functions[i];
	}
	delete[]functions;
	functions = nullptr;
	size = capacity = 0;
}

void FunctionCollection::copyFrom(const FunctionCollection& other)
{
	functions = new PartialFunction * [other.capacity];
	for (int i = 0; i < other.size; i++)
	{
		functions[i] = other.functions[i]->clone();
	}
	capacity = other.capacity;
	size = other.size;
}

void FunctionCollection::moveFrom(FunctionCollection&& other)
{
	functions = other.functions;
	size = other.size;
	capacity = other.capacity;

	other.functions = nullptr;
	other.size = other.capacity = 0;
}

void FunctionCollection::resize(size_t newSize)
{
	PartialFunction** temp = new PartialFunction * [newSize];
	for (int i = 0; i < size; i++)
	{
		temp[i] = functions[i];
	}
	delete[]functions;
	functions = temp;
	capacity = newSize;
}

FunctionCollection::FunctionCollection()
{
	size = 0;
	capacity = 8;
	functions = new PartialFunction * [capacity];
}

FunctionCollection::FunctionCollection(size_t capacity)
{
	functions = new PartialFunction * [capacity];
	this->capacity = capacity;
	size = 0;
}


FunctionCollection::FunctionCollection(const FunctionCollection& other)
{
	copyFrom(other);
}

FunctionCollection& FunctionCollection::operator=(const FunctionCollection& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

FunctionCollection::FunctionCollection(FunctionCollection&& other) noexcept
{
	moveFrom(std::move(other));
}

FunctionCollection& FunctionCollection::operator=(FunctionCollection&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

FunctionCollection::~FunctionCollection()
{
	free();
}

void FunctionCollection::addFunction(PartialFunction* func)
{
	if (size == capacity)
		resize(capacity * 2);
	functions[size++] = func->clone();
}

size_t FunctionCollection::getSize() const
{
	return size;
}

const PartialFunction* FunctionCollection::operator[](int ind) const
{
	return functions[ind];
}
