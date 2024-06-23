#include "MakeDirectory.h"
#include "../../SystemObject/SystemObjectFactory.h"

Command* MakeDirectory::clone() const
{
	return new MakeDirectory(*this);
}

void MakeDirectory::execute(FileSubsystem& system) const
{
	Directory* currDirectory = system.getCurrentDirectory();

	SystemObjectFactory factory = SystemObjectFactory::getInstance();

	currDirectory->add( factory.create(EnumClasses::TypeOfObject::directory) );

	currDirectory->setItem(this->name, getCurrDateAndTime(), currDirectory->getSize() - 1);
}

void MakeDirectory::saveInDataFile(std::ofstream& ofs) const
{
	EnumClasses::TypeOfCommand type = EnumClasses::TypeOfCommand::mkdir;

	ofs.write(reinterpret_cast<const char*>(&type), sizeof(type));
	this->name.writeInDataFile(ofs);
}

void MakeDirectory::loadFromDataFile(std::ifstream& ifs)
{
	this->name.readFromDataFile(ifs);
}

void MakeDirectory::loadFromStrStream(std::stringstream& strStream)
{
	char buffer[GLOBAL_CONSTS_MYSTRING::MAX_BUFFER_SIZE];
	strStream.getline(buffer, GLOBAL_CONSTS_MYSTRING::MAX_BUFFER_SIZE, GLOBAL_CONSTS::COMMAND_SEP);

	this->name = (MyString)buffer;
}
