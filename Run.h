#pragma once
#include "MyString.h"
#include "CriteriaPartialFunction.hpp"
#include "Factory.h"
#include "ReadFromFile.h"

class Run
{
	MyString fileName;

public:
	Run(const MyString& fileName) :fileName(fileName) {};
	void runProgram()const;
	void FuncInRange()const;
	void NextVal()const;
	
};

