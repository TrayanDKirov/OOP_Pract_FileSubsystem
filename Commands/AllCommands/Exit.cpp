#include "Exit.h"

Command* Exit::clone() const
{
    return new Exit(*this);
}

void Exit::execute(FileSubsystem& system) const
{
    system.end();
}

void Exit::saveInDataFile(std::ofstream& ofs) const
{
	EnumClasses::TypeOfCommand type = EnumClasses::TypeOfCommand::exit;

	ofs.write(reinterpret_cast<const char*>(&type), sizeof(type));
}

void Exit::loadFromDataFile(std::ifstream& ifs)
{

}

void Exit::loadFromStrStream(std::stringstream& strStream)
{

}
