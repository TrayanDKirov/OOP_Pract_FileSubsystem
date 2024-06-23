#include "SystemObjectFactory.h"
#include "Directory.h"
#include "File/LinkFile.h"
#include "File/ScriptFile.h"
#include "File/TextFile.h"

File* SystemObjectFactory::createFile(EnumClasses::TypeOfObject type) const
{
	switch (type)
	{
	case EnumClasses::TypeOfObject::textFile: return static_cast<File*>(new TextFile());
		break;
	case EnumClasses::TypeOfObject::scriptFile: return static_cast<File*>(new ScriptFile());
		break;
	case EnumClasses::TypeOfObject::linkFile: return static_cast<File*>(new LinkFile());
		break;
	default:
		throw std::logic_error("Invalid type of object in SystemObjectFactory::create()");
		break;
	}
}

File* SystemObjectFactory::createFileByName(const MyString& nameOfFile) const
{
	EnumClasses::TypeOfObject type;

	const char* ptr = nameOfFile.c_str();
	const char* ptrToMove = nameOfFile.c_str() + (nameOfFile.getLen() - 1);
	size_t counter = 1;

	MyString ext;
	while (ptr != ptrToMove)
	{
		if (*ptrToMove == '.')
		{
			ext = nameOfFile.subStr(ptrToMove - ptr, counter);
		}

		counter++;
		ptrToMove--;
	}

	if (ext == "")
	{
		throw std::logic_error("File has no extention. In SystemObjectFactory::createFileByName()");
	}

	FileExtentions fileExtentions;
	type = fileExtentions.getTypeOfFile(ext);

	return createFile(type);
}

SystemObject* SystemObjectFactory::create(EnumClasses::TypeOfObject type) const
{
	switch (type)
	{
	case EnumClasses::TypeOfObject::directory: return static_cast<SystemObject*>(new Directory());
		break;
	default:
		return static_cast<SystemObject*>(createFile(type));
		break;
	}
}

SystemObject* SystemObjectFactory::create(std::ifstream& ifs) const
{
	EnumClasses::TypeOfObject type;

	ifs.read(reinterpret_cast<char*>(&type), sizeof(type));

	SystemObject* result = create(type);

	result->loadFromDataFile(ifs);
	return result;
}


SystemObjectFactory& SystemObjectFactory::getInstance()
{
	static SystemObjectFactory result;

	return result;
}
