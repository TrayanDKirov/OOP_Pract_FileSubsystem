#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include "Command.h"

namespace GLOBAL_CONSTS_COMMANDS
{
	constexpr size_t MAX_BUFF_SIZE = 1024;
	const char COMMAND_SEP = ' ';
}

class CommandFactory
{

	CommandFactory() = default;

public:

	Command* create(EnumClasses::TypeOfCommand type) const;
	Command* create(std::stringstream& strStream) const;
	Command* create(std::ifstream& ifs) const;

	static CommandFactory& getInstance();
};