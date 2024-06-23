#include "RemoveFile.h"

Command* RemoveFile::clone() const
{
    return new RemoveFile(*this);
}

void RemoveFile::execute(FileSubsystem& system) const
{
    File* file;
    if (file = dynamic_cast<File*>(this->path.getObjectFromPath(system)))
    {
        size_t index = file->getParentDirecory()->getIndexOfObject(file);// Should not throw any exception
        file->getParentDirecory()->remove(index);
        return;
    }

    throw std::invalid_argument("Path is to directory. ");
}

void RemoveFile::saveInDataFile(std::ofstream& ofs) const
{
    EnumClasses::TypeOfCommand type = EnumClasses::TypeOfCommand::rm;

    ofs.write(reinterpret_cast<const char*>(&type), sizeof(type));
    this->path.writeInDataFile(ofs);
}

void RemoveFile::loadFromDataFile(std::ifstream& ifs)
{
    this->path.readFromDataFile(ifs);
}

void RemoveFile::loadFromStrStream(std::stringstream& strStream)
{
    char buffer[GLOBAL_CONSTS_MYSTRING::MAX_BUFFER_SIZE];
    strStream.getline(buffer, GLOBAL_CONSTS_MYSTRING::MAX_BUFFER_SIZE, GLOBAL_CONSTS::COMMAND_SEP);

    this->path = (MyString)buffer;
}
