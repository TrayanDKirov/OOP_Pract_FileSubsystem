#include "LinkFile.h"

void LinkFile::loadFromDataFile(std::ifstream& ifs)
{
	this->pathInDirectory.readFromDataFile(ifs);
}

void LinkFile::saveInDataFile(std::ofstream& ofs) const
{
	EnumClasses::TypeOfObject type = EnumClasses::TypeOfObject::linkFile;

	ofs.write(reinterpret_cast<const char*>(&type), sizeof(type));
	this->pathInDirectory.writeInDataFile(ofs);
}

SystemObject* LinkFile::clone() const
{
	return new LinkFile(*this);
}
