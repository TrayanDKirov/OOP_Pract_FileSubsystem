#pragma once
#include <iostream>

class Command
{

public:

	virtual void execute() const = 0;
	virtual Command* clone() const = 0;

	virtual ~Command() = default;
};