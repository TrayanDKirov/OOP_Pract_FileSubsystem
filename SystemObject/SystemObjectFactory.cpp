#include "SystemObjectFactory.h"
#include "Directory.h"
#include "File/LinkFile.h"
#include "File/ScriptFile.h"
#include "File/TextFile.h"
#include "../Utils.h"

Directory* SystemObjectFactory::createDirectory(std::ifstream& ifs)
{
	Directory* result = new Directory();

	result->loadFromDataFile(ifs);
	return result;
}

File* SystemObjectFactory::createFile(std::ifstream& ifs)
{
	MyString pathToFile;
	pathToFile.readFromDataFile(ifs);

	MyString ext = pathToFile.subStr(pathToFile.getLen() - 3, 3);
	TypeOfObject typeOfFile = fileExtentions.getTypeOfFile(ext);

	File* result;
	switch (typeOfFile)
	{
	case TypeOfObject::textFile: result = static_cast<File*>(new TextFile());
		break;
	case TypeOfObject::scriptFile: result = static_cast<File*>(new ScriptFile());
		break;
	case TypeOfObject::linkFile: result = static_cast<File*>(new LinkFile());
		break;
	default:
		break;
	}

	result->setPathToFile(pathToFile);
	result->loadFromDataFile(ifs);

	return result;
}

SystemObject* SystemObjectFactory::create(std::ifstream& ifs)
{
	TypeOfObject type;

	ifs.read(reinterpret_cast<char*>(&type), sizeof(type));

	switch (type)
	{
	case TypeOfObject::directory: return static_cast<SystemObject*>(createDirectory(ifs));
		break;
	case TypeOfObject::file: return static_cast<SystemObject*>(createFile(ifs));
		break;
	default:
		break;
	}
}

SystemObjectFactory& SystemObjectFactory::getInstance()
{
	static SystemObjectFactory result;

	return result;
}
