#pragma once
#include "ParticialFunction.h"

class ParticialFunctionOperation:public ParticialFunction
{
protected:
	ParticialFunction** functions = nullptr;
	uint16_t size = 0;

private:
	void free();
	void copyFrom(const ParticialFunctionOperation& other);
	void moveFrom(ParticialFunctionOperation&& other);

public:
	ParticialFunctionOperation(ParticialFunction**&& functions, uint16_t size);
	ParticialFunctionOperation(const ParticialFunctionOperation& other);
	ParticialFunctionOperation& operator=(const ParticialFunctionOperation& other);
	ParticialFunctionOperation(ParticialFunctionOperation&& other)noexcept;
	ParticialFunctionOperation& operator=(ParticialFunctionOperation&& other)noexcept;
	~ParticialFunctionOperation()noexcept;

	bool isDefined(int32_t val)const override;
};




