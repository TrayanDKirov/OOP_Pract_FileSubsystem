#include "NamesOfCommands.h"

NamesOfCommands::NamesOfCommands()
{
	this->arrOfNames[0] = "cd";
	this->arrOfNames[1] = "echo";
	this->arrOfNames[2] = "exec";
	this->arrOfNames[3] = "exit";
	this->arrOfNames[4] = "find";
	this->arrOfNames[5] = "ls";
	this->arrOfNames[6] = "mkdir";
	this->arrOfNames[7] = "pwd";
	this->arrOfNames[8] = "rm";
	this->arrOfNames[9] = "rmdir";
	this->arrOfNames[10] = "touch";
}

size_t NamesOfCommands::binarySearch(const MyString& str) const
{
	size_t left = 0;
	size_t right = this->sizeOfArr - 1;

	while (left <= right)
	{
		size_t mid = (right - left) / 2 + left;

		if (str < this->arrOfNames[mid])
		{
			right = mid - 1;
		}
		else if (str > this->arrOfNames[mid])
		{
			left = mid + 1;
		}
		else
		{
			return mid;
		}
	} 

	throw std::logic_error("Str not in NamesOfCommands::arrOfNames");
}

EnumClasses::TypeOfCommand NamesOfCommands::getTypeOfCommand(const MyString& str) const
{
	try
	{
		size_t index;
		index = binarySearch(str);

		return (EnumClasses::TypeOfCommand)(index);
	}
	catch (std::logic_error& ex)
	{
		throw std::logic_error("Incorrect nameOfCommand ");
	}
	catch (...)
	{
		throw std::exception("Unknown error. ");
	}
}

const MyString* NamesOfCommands::getNameOfCommand(const MyString& nameOfCommand)
{
	try
	{
		size_t index;
		index = binarySearch(nameOfCommand);

		return arrOfNames + index;
	}
	catch (std::logic_error& ex)
	{
		throw std::logic_error("Error occured in naming a command. ");
	}
	catch (...)
	{
		throw std::exception("Unknown error. ");
	}
}

NamesOfCommands& NamesOfCommands::getInstance()
{
	static NamesOfCommands result;

	return result;
}