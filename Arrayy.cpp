#include "Arrayy.h"
#include <iostream>

void Arrayy::free()
{
	delete[] data;
}
void Arrayy::copyFrom(const Arrayy& other)
{
	data = new int[other.size];
	for (int i = 0; i < other.size; i++) {
		data[i] = other.data[i];
	}
	size = other.size;
}
void Arrayy::moveFrom(Arrayy&& other)
{
	data = other.data;
	size = other.size;
	other.data = nullptr;
	other.size = 0;
}
Arrayy::Arrayy()
{
	size = 0;
	data = nullptr;

}
Arrayy::Arrayy(int* data, int size)
{
	if (!data) {
		throw std::exception("data cannot be nullptr");
	}
	this->data = new int[size];
	for (int i = 0; i < size; i++) {
		this->data[i] = data[i];
	}
	this->size = size;
}

Arrayy::~Arrayy()
{
	free();
}

Arrayy& Arrayy::operator=(const Arrayy& other)
{
	if (this != &other) {
		free();
		copyFrom(other);
	}
	return *this;
}

Arrayy::Arrayy(const Arrayy& other)
{
	copyFrom(other);
}

Arrayy& Arrayy::operator=(Arrayy&& other) noexcept
{
	if (this != &other) {
		free();
		moveFrom(std::move( other));
	}
	return *this;
}

Arrayy::Arrayy(Arrayy&& other) noexcept
{
	moveFrom(std::move(other));
}

int Arrayy::operator[](int index) const
{
	return data[index];
}

const int* Arrayy::getData() const
{
	return data;
}

int Arrayy::getSize() const
{
	return size;
}