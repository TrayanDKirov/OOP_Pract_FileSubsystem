#include "PrintWorkingDir.h"

Command* PrintWorkingDirectory::clone() const
{
    return static_cast<Command*>(new PrintWorkingDirectory(*this));
}

void PrintWorkingDirectory::execute(FileSubsystem& system) const
{
    PathInSystem path;
    path.initPathByDirectory(system);

    std::cout << path;
}

void PrintWorkingDirectory::saveInDataFile(std::ofstream& ofs) const
{
    EnumClasses::TypeOfCommand type = EnumClasses::TypeOfCommand::pwd;

    ofs.write(reinterpret_cast<const char*>(&type), sizeof(type));
}

void PrintWorkingDirectory::loadFromDataFile(std::ifstream& ifs)
{

}

void PrintWorkingDirectory::loadFromStrStream(std::stringstream& strStream)
{

}
