#include "System.h"

void System::initializeSystem(const MyString& dataFilePath)
{
	this->dataFilePath = dataFilePath;

	std::ifstream dataFile(dataFilePath.c_str(), std::ios::binary | std::ios::in);
	if (!dataFile.is_open())
	{
		throw std::runtime_error("DataFile did not open in System::run()");
	}

	SystemObjectFactory factory = SystemObjectFactory::getInstance();
	if (!(this->rootDirectory = dynamic_cast<Directory*>( factory.createObject(dataFile) )) )
	{
		throw std::runtime_error("Root directory not found. ");
	}

	this->currentDirectory = this->rootDirectory;
}

void System::run(const MyString& dataFilePath)
{
	initializeSystem(dataFilePath);


}