#pragma once
#include "../MyString/MyString.h"
#include "../Utils.h"

class NamesOfCommands
{
	MyString arrOfNames[GLOBAL_CONSTS::NUMBER_OF_COMMANDS];
	size_t sizeOfArr = GLOBAL_CONSTS::NUMBER_OF_COMMANDS;


	size_t binarySearch(const MyString& str) const;

public:
	NamesOfCommands();

	EnumClasses::TypeOfCommand getTypeOfCommand(const MyString& str) const;

	const MyString* getNameOfCommand(const MyString& nameOfCommand);

	static NamesOfCommands& getInstance();
};