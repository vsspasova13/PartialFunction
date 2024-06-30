#include "Run.h"
#include "ParticialFunctionsFactory.h"

void run(const char* fileName)
{
	ParticialFunction* function = ParticialFunctionsFactory::create(fileName);
	uint16_t n;
	std::cout << "Choose mode:" << std::endl;
	std::cout << "1-print chosen values in [a;b]" << std::endl;
	std::cout << "2-print all defined values" << std::endl;
	std::cin >> n;

	switch (n)
	{
	case 1:
		funcByValues(function);
		break;
	case 2:
		allValues(function);
		break;
	default:
		std::cout << "Error." << std::endl;
		break;
	}
}

void funcByValues(const ParticialFunction* funct)
{
	std::cout << "Type a and b:"<<std::endl;
	uint16_t a, b;
	std::cin >> a >> b;
	if (a > b)
	{
		throw std::invalid_argument("Error.");
	}

	for (size_t i = a; i < b; i++)
	{
		if (funct->isDefined(i)); {
			std::cout << "f(" << i << ")= " << (*funct)(i) << std::endl;
		}
	}

}

void allValues(const ParticialFunction* funct)
{
	std::cin.ignore();
	std::cout << "Press enter to output one defined value:";
	for (size_t i = INT32_MIN; i < INT32_MAX; i++)
	{
		if (funct->isDefined(i)) {
			std::cin.ignore();
			std::cout << "f(" << i << ")= " << (*funct)(i) << std::endl;
		}
	}
}
