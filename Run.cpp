#include "Run.h"
#include <iostream>

void Run::runProgram() const
{
	int n;
	std::cout << "Choose mode: 1-FunctionInRange 2-NextValue 3-Exit" << std::endl;
	std::cin >> n;
	switch (n)
	{
	case 1:
		FuncInRange();
		break;
	case 2:
		NextVal();
		break;
	case 3:
		return;
		break;
	}
}

void Run::FuncInRange() const
{
	int a, b;
	std::cout << "Enter a:";
	std::cin >> a;
	std::cout << "Enter b:";
	std::cin >> b;
	std::cout << std::endl;
	if (a > b)
		throw std::invalid_argument("A trqbva da e po-malko ot B");
	ReadFromFile h(fileName);
	PartialFunction* ptr(h.handleCase());
	for (int i = a; i < b; i++)
	{
		if (!ptr->isDefinedAt(i))continue;
		std::cout << "f(" << i << ")=" << ptr->compute(i);
	}
}

void Run::NextVal() const
{
	std::cout << "Enter start value:";
	int n;
	std::cin >> n;
	char ch;
	ReadFromFile h(fileName);
	PartialFunction* ptr(h.handleCase());
	int i = n;
	do
	{
		while (!ptr->isDefinedAt(++i)) 
		{}
			std::cout << "f(" << i << ")=" << ptr->compute(i);
			std::cout << "Do you want next value(Y-yes, N-no):";
			std::cin >> ch;
		
	} while (ch == 'Y');
	return;
}
