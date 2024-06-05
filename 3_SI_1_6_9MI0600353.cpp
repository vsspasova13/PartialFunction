#pragma once
#include <iostream>
#include "CriteriaPartialFunction.hpp"
#include "ReadFromFile.h"
#include "FunctObj0.h"
#include <fstream>
#include "Run.h"

int main()
{
    MyString file = "func.dat";
    Run r(file);
    r.runProgram();

}
