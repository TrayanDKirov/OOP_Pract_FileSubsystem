#include <sstream>
#include "PathInSystem.h"

PathInSystem::PathInSystem(const MyString& pathToFile)
{
	this->pathToFile = pathToFile;

	const char* ptrToMove = this->pathToFile.c_str();

	while (*ptrToMove)
	{
		if (*ptrToMove == GLOBAL_CONSTS::SEP_IN_PATH)
		{
			this->isAbsolute = true;
			break;
		}
		ptrToMove++;
	}
}

void PathInSystem::initPathByDirectory(Directory* dir, const FileSubsystem& system)
{
	Directory* currDirectory = dir;

	while (currDirectory != system.rootDirectory)
	{
		pathToFile = ("/" + currDirectory->getName()) + pathToFile;

		currDirectory = currDirectory->getParentDirecory();
	}

	pathToFile = ("/" + currDirectory->getName()) + pathToFile;
}

void PathInSystem::initPathByDirectory(const FileSubsystem& system)
{
	initPathByDirectory(system.currentDirectory, system);
}

SystemObject* PathInSystem::getObjectFromPath(const FileSubsystem& system) const
{
	if (this->pathToFile == "")
	{
		return static_cast<SystemObject*>(system.currentDirectory);
	}
	if (this->pathToFile == "..")
	{
		Directory* currDirectory = system.currentDirectory;
		Directory* parentDirectory = currDirectory->getParentDirecory();
		if (parentDirectory == nullptr)
		{
			return static_cast<SystemObject*>(currDirectory);
		}
		return static_cast<SystemObject*>(parentDirectory);
	}

	Directory* currDirectory = system.rootDirectory;
	std::stringstream strStream(this->pathToFile.c_str());

	char buffer[GLOBAL_CONSTS_MYSTRING::MAX_BUFFER_SIZE];
	strStream.getline(buffer, GLOBAL_CONSTS_MYSTRING::MAX_BUFFER_SIZE, GLOBAL_CONSTS::SEP_IN_PATH);
	while (true)
	{
		strStream.getline(buffer, GLOBAL_CONSTS_MYSTRING::MAX_BUFFER_SIZE, GLOBAL_CONSTS::SEP_IN_PATH);
		if (strStream.eof())
		{
			return currDirectory->getObjectByName(buffer);
		}
		
		SystemObject* object = currDirectory->getObjectByName(buffer);
		if (currDirectory = dynamic_cast<Directory*>(object))
		{
			throw std::invalid_argument("Path is invalid. ");
		}
	}
}

void PathInSystem::readFromDataFile(std::ifstream& ifs)
{
	this->pathToFile.readFromDataFile(ifs);
}

void PathInSystem::writeInDataFile(std::ofstream& ofs) const
{
	this->pathToFile.writeInDataFile(ofs);
}

std::ostream& operator<<(std::ostream& os, const PathInSystem& path)
{
	return os << path.pathToFile;
}
