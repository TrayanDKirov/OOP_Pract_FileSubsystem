#include "ChangeDirectory.h"

Command* ChangeDirectory::clone() const
{
	return static_cast<Command*>(new ChangeDirectory(*this));
}

void ChangeDirectory::execute(FileSubsystem& system) const
{
	if (Directory* dir = dynamic_cast<Directory*>(this->path.getObjectFromPath(system)))
	{
		system.setCurrentDirectory(dir);
		return;
	}

	throw std::invalid_argument("Path is to file");
}

void ChangeDirectory::saveInDataFile(std::ofstream& ofs) const
{
	EnumClasses::TypeOfCommand type = EnumClasses::TypeOfCommand::cd;

	ofs.write(reinterpret_cast<const char*>(&type), sizeof(type));
	this->path.writeInDataFile(ofs);
}

void ChangeDirectory::loadFromDataFile(std::ifstream& ifs)
{
	this->path.readFromDataFile(ifs);
}

void ChangeDirectory::loadFromStrStream(std::stringstream& strStream)
{
	char buffer[GLOBAL_CONSTS_MYSTRING::MAX_BUFFER_SIZE];
	strStream.getline(buffer, GLOBAL_CONSTS_MYSTRING::MAX_BUFFER_SIZE, GLOBAL_CONSTS::COMMAND_SEP);
	
	this->path = (MyString)buffer;
}
