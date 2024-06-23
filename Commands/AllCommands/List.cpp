#include "List.h"

Command* List::clone() const
{
    return static_cast<Command*>(new List(*this));
}

void List::execute(FileSubsystem& system) const
{
    if (Directory* dir = dynamic_cast<Directory*>(this->path.getObjectFromPath(system)))
    {
        dir->printInfoOfObjects(std::cout);
        return;
    }

    throw std::invalid_argument("Path is to file");
}

void List::saveInDataFile(std::ofstream& ofs) const
{
    EnumClasses::TypeOfCommand type = EnumClasses::TypeOfCommand::ls;

    ofs.write(reinterpret_cast<const char*>(&type), sizeof(type));
    this->path.writeInDataFile(ofs);
}

void List::loadFromDataFile(std::ifstream& ifs)
{
    this->path.readFromDataFile(ifs);
}

void List::loadFromStrStream(std::stringstream& strStream)
{
    char buffer[GLOBAL_CONSTS_MYSTRING::MAX_BUFFER_SIZE];
    strStream.getline(buffer, GLOBAL_CONSTS_MYSTRING::MAX_BUFFER_SIZE, GLOBAL_CONSTS::COMMAND_SEP);

    this->path = (MyString)buffer;
}
