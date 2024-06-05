#include "FunctObj.h"

FunctObj::FunctObj(const int* arr, size_t size)
{
	this->arr = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		this->arr[i] = arr[i];
	}
	this->size = size;
}
