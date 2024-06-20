#pragma once
#include <fstream>
#include "Directory.h"
#include "File/LinkFile.h"
#include "File/ScriptFile.h"
#include "File/TextFile.h"

enum class TypeOfObject : unsigned char
{
	directory = 0,
	file = 1
};

class SystemObjectFactory
{


	SystemObjectFactory() = default;

	Directory* createDirectory(std::ifstream& ifs) const;
	File* createFile(std::ifstream& ifs) const;

public:

	SystemObject* createObject(std::ifstream& ifs) const;

	static SystemObjectFactory& getInstance();
};