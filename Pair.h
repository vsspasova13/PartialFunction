#pragma once
#include <iostream>
#include <fstream>
class Pair
{
public:
	bool isDefined = false;
	int value = 0;

public:
	Pair(bool isDef, int value);
	friend std::ostream& operator<<(std::ostream& os, const Pair& other);
};

