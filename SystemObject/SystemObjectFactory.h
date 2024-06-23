#pragma once
#include <iostream>
#include <fstream>
#include "SystemObject.h"
#include "../Utils.h"
#include "File/File.h"

class SystemObjectFactory
{

	SystemObjectFactory() = default;

	File* createFile(EnumClasses::TypeOfObject type) const;

public:

	File* createFileByName(const MyString& nameOfFile) const;
	SystemObject* create(EnumClasses::TypeOfObject type) const;
	SystemObject* create(std::ifstream& ifs) const;

	static SystemObjectFactory& getInstance();

};