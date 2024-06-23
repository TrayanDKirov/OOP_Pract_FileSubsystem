#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "NamesOfCommands.h"
#include "../Utils.h"
#include "../System/FileSubsystem.h"

class Command
{
protected:

	const MyString* nameOfCommand;
public:


	virtual void execute(FileSubsystem& system) const = 0;
	virtual Command* clone() const = 0;

	virtual void saveInDataFile(std::ofstream& ofs) const = 0;
	virtual void loadFromDataFile(std::ifstream& ifs) = 0;

	virtual void loadFromStrStream(std::stringstream& strStream) = 0;

	virtual ~Command() = default;
};