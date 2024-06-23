#include "Touch.h"
#include "../../SystemObject/SystemObjectFactory.h"

Command* Touch::clone() const
{
    return static_cast<Command*>(new Touch(*this));
}

void Touch::execute(FileSubsystem& system) const
{
    Directory* currDirectory = system.getCurrentDirectory();
    try
    {
        SystemObject* file = currDirectory->getObjectByName(this->name);

        file->setModificationDate(getCurrDateAndTime());
        throw std::invalid_argument("This name is taken. ");
    }
    catch (std::invalid_argument& ex)
    {
        SystemObjectFactory factory = SystemObjectFactory::getInstance();
        currDirectory->add(static_cast<SystemObject*>(factory.createFileByName(this->name)));

        currDirectory->setItem(this->name, getCurrDateAndTime(), currDirectory->getSize() - 1);
        return;
    }
    catch (...)
    {

    }
}

void Touch::saveInDataFile(std::ofstream& ofs) const
{
    EnumClasses::TypeOfCommand type = EnumClasses::TypeOfCommand::touch;

    ofs.write(reinterpret_cast<const char*>(&type), sizeof(type));
    this->name.writeInDataFile(ofs);
}

void Touch::loadFromDataFile(std::ifstream& ifs)
{
    this->name.readFromDataFile(ifs);
}

void Touch::loadFromStrStream(std::stringstream& strStream)
{
    char buffer[GLOBAL_CONSTS_MYSTRING::MAX_BUFFER_SIZE];
    strStream.getline(buffer, GLOBAL_CONSTS_MYSTRING::MAX_BUFFER_SIZE, GLOBAL_CONSTS::COMMAND_SEP);

    this->name = (MyString)buffer;
}
