#pragma once
#include "../MyString/MyString.h"
#include "FileSubsystem.h"
#include "../SystemObject/Directory.h"
#include "../Utils.h"

class PathInSystem
{
	MyString pathToFile;
	bool isAbsolute = false;

public:

	PathInSystem() = default;
	PathInSystem(const MyString& pathToFile);

	void initPathByDirectory(Directory* dir, const FileSubsystem& system);
	void initPathByDirectory(const FileSubsystem& system);

	SystemObject* getObjectFromPath(const FileSubsystem& system) const;

	void readFromDataFile(std::ifstream& ifs);
	void writeInDataFile(std::ofstream& ofs) const;

	friend std::ostream& operator<<(std::ostream& os, const PathInSystem& path);
};