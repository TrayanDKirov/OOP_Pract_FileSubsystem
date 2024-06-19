#pragma once
#include "SystemObject.h"

class Directory : public SystemObject
{
public:

	SystemObject* clone() const override
	{
		return new Directory(*this);
	}
	
	void print() const override
	{
		std::cout << "Directory" << std::endl;
	}

	~Directory() override = default;
};