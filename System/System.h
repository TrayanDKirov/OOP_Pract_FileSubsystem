#pragma once
#include "../SystemObject/Directory.h"
#include "../SystemObject/SystemObjectFactory.h"
#include <fstream>

class System
{
	Directory* rootDirectory = nullptr;
	Directory* currentDirectory = nullptr;
	MyString dataFilePath;

	void initializeSystem(const MyString& dataFilePath);

public:

	void run(const MyString& dataFilePath);

};