#pragma once
#include <iostream>
#include <fstream>

class Command
{

public:

	virtual void execute() const = 0;
	virtual Command* clone() const = 0;
	virtual void writeInTextFile(std::ostream& os);

	virtual ~Command() = default;
};