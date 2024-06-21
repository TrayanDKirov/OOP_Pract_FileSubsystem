#include "LinkFile.h"

void LinkFile::saveFile(std::ostream& os) const
{
	os << this->pathInDirectory;
}

void LinkFile::saveFile() const
{
	std::ofstream ofs(this->pathToFile.c_str(), std::ios::out | std::ios::trunc);
	if (!ofs.is_open())
	{
		throw std::runtime_error("File did not open in LinkFile::saveFile()");
	}

	saveFile(ofs);
	ofs.close();
}

void LinkFile::loadFromDataFile(std::ifstream& ifs)
{
}

void LinkFile::saveInDataFile(std::ofstream& ofs) const
{
	saveFile();

	TypeOfObject type = TypeOfObject::file;

	ofs.write(reinterpret_cast<const char*>(&type), sizeof(type));
	File::savePathToDataFile(ofs);
}

SystemObject* LinkFile::clone() const
{
	return new LinkFile(*this);
}
