#pragma once
#include <iostream>
#include <fstream>
#include "SystemObject.h"

class Directory;
class File;

class SystemObjectFactory
{

	SystemObjectFactory() = default;

	Directory* createDirectory(std::ifstream& ifs);
	File* createFile(std::ifstream& ifs);

public:

	SystemObject* create(std::ifstream& ifs);

	static SystemObjectFactory& getInstance();

};