#pragma once
#include "../SystemObject/Directory.h"
#include "../SystemObject/SystemObjectFactory.h"
#include <fstream>

class FileSubsystem
{
	Directory* rootDirectory = nullptr;
	Directory* currentDirectory = nullptr;
	MyString dataFilePath;

public:
	void initializeSystem(const MyString& dataFilePath);

	void setCurrentDirectory(Directory* direcotyToSet);
	Directory* getCurrentDirectory();
	const Directory* getCurrentDirectory() const;

	void run(const MyString& dataFilePath);

	void end();

	friend class PathInSystem;
};