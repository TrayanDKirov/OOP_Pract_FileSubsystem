#include "Directory.h"

SystemObject* Directory::clone() const 
{
	return new Directory(*this);
}

void Directory::loadFromDataFile(std::ifstream& ifs)
{
	SystemObject::loadData(ifs);

	SystemObjectContainer::loadFromDataFile(ifs, this);
}

void Directory::saveInDataFile(std::ofstream& ofs) const
{
	EnumClasses::TypeOfObject type = EnumClasses::TypeOfObject::directory;
	ofs.write(reinterpret_cast<const char*>(&type), sizeof(type));

	SystemObject::saveData(ofs);

	SystemObjectContainer::saveInDataFile(ofs);
}

void Directory::printInfoOfObjects(std::ostream& os) const
{
	SystemObjectContainer::printInfoAboutObjects(os);
}
