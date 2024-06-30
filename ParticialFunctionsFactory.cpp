#include "ParticialFunctionsFactory.h"
#include "CriteriaParticialFunction.hpp"
#include "MaxParticialFunction.h"
#include "MinParticialFunction.h"
#include "TypeOneFunction.h"
#include "TypeTwoFunction.h"
#include "TypeZeroFunction.h"

constexpr unsigned MAX_VALUE = 32;

static unsigned getWordLength(std::ifstream& file)
{
	unsigned curr = file.tellg();
	unsigned length = 0;
	while (file.get())
	{
		length++;
	}
	file.seekg(curr);
	return length;
}

ParticialFunction* ParticialFunctionsFactory::create(const char* fileName)
{
	if (!fileName || fileName[0] == '\0')
	{
		throw std::invalid_argument("Invalid file name.");
	}
	std::ifstream ifs(fileName, std::ios::binary| std::ios::in);
	if (!ifs.is_open())
		throw std::exception("Couldn't open the file.");
	return create(ifs);
}

ParticialFunction* ParticialFunctionsFactory::create(std::ifstream& ifs)
{
	uint16_t n, t;
	ifs.read((char*)&n, sizeof(n));
	if (n > MAX_VALUE)
		throw std::invalid_argument("Invalid number");
	ifs.read((char*)&t, sizeof(t));
	if (t == 0)
	{
		TypeZeroFunction f(n, ifs);
		return new CriteriaParticialFunction<TypeZeroFunction>(f);
	}
	else if (t == 1)
	{
		TypeOneFunction f(n, ifs);
		return new CriteriaParticialFunction<TypeOneFunction>(f);
	}
	else if (t == 2)
	{
		TypeTwoFunction f(n, ifs);
		return new CriteriaParticialFunction<TypeTwoFunction>(f);
	}
	else if (t == 3)
	{
		ParticialFunction** arr = createArr(ifs, n);
		ParticialFunction* temp = new MaxParticialFunction(std::move(arr), n);
		delete[]arr;
		return temp;
	}
	else if (t == 4)
	{
		ParticialFunction** arr = createArr(ifs, n);
		ParticialFunction* temp = new MinParticialFunction(std::move(arr), n);
		delete[]arr;
		return temp;
	}
	else
	{
		throw std::invalid_argument("Error.");
	}
}

ParticialFunction** ParticialFunctionsFactory::createArr(std::ifstream& ifs, uint16_t size)
{
	ParticialFunction** arr = new ParticialFunction * [size] {nullptr};
	int ind = 0;

	while (size--)
	{
		uint16_t wordSize = getWordLength(ifs);
		char* buff = new char[wordSize + 1];
		ifs.read((char*)buff, wordSize+1);
		arr[ind++] = create(buff);
		delete[]buff;
	}
	return arr;

}
