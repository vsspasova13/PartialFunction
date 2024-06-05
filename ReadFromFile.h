#pragma once
#include "Factory.h"
#include "Vector.hpp"
#include "MyString.h"

class ReadFromFile
{
public:
	ReadFromFile(const MyString& fileName);
	void readStrings(std::ifstream& ifs, Vector<MyString>& vect);
	PartialFunction* handleCase();

private:
	MyString fileName;
};


