#include "FileSubsystem.h"
#include "../Commands/CommandFactory.h"
#include "../DateAndTime/CurrentDate.h"

static size_t getFileSize(std::ifstream& f)
{
	size_t currentPos = f.tellg();
	f.seekg(0, std::ios::end);
	size_t size = f.tellg();

	f.seekg(currentPos);
	return size;
}

void FileSubsystem::initializeSystem(const MyString& dataFilePath)
{
	this->dataFilePath = dataFilePath;

	std::ifstream dataFile(dataFilePath.c_str(), std::ios::binary | std::ios::in);
	if (!dataFile.is_open())
	{
		throw std::runtime_error("DataFile did not open in System::run()");
	}

	size_t sizeOfFile = getFileSize(dataFile);
	if (sizeOfFile == 0)
	{
		this->rootDirectory = this->currentDirectory = new Directory();

		this->rootDirectory->setName("root");
		this->rootDirectory->setCreationDate(getCurrDateAndTime());
		this->rootDirectory->setModificationDate(getCurrDateAndTime());

		dataFile.close();
		return;
	}

	SystemObjectFactory factory = SystemObjectFactory::getInstance();
	if (!(this->rootDirectory = dynamic_cast<Directory*>( factory.create(dataFile) )) )
	{
		throw std::runtime_error("Root directory not found. ");
	}

	this->currentDirectory = this->rootDirectory;
}

void FileSubsystem::setCurrentDirectory(Directory* direcotyToSet)
{
	this->currentDirectory = direcotyToSet;
}

Directory* FileSubsystem::getCurrentDirectory()
{
	return this->currentDirectory;
}

const Directory* FileSubsystem::getCurrentDirectory() const
{
	return this->currentDirectory;
}

void FileSubsystem::run(const MyString& dataFilePath)
{
	initializeSystem(dataFilePath);

	CommandFactory factory = CommandFactory::getInstance();

	MyString line;
	while (true)
	{
		std::cin >> line;
		std::stringstream strStream(line.c_str());

		Command* command = factory.create(strStream);
		command->execute(*this);
	}
}