#include "TextFile.h"

void TextFile::saveFile(std::ostream& os) const
{
	os << this->dataFromFile;
}

void TextFile::saveFile() const
{
	std::ofstream ofs(this->pathToFile.c_str(), std::ios::out | std::ios::trunc);
	if (!ofs.is_open())
	{
		throw std::runtime_error("File did not open in LinkFile::saveFile()");
	}

	saveFile(ofs);
	ofs.close();
}

void TextFile::loadFromDataFile(std::ifstream& ifs)
{

}

void TextFile::saveInDataFile(std::ofstream& ofs) const
{
	saveFile();

	TypeOfObject type = TypeOfObject::file;

	ofs.write(reinterpret_cast<const char*>(&type), sizeof(type));
	File::savePathToDataFile(ofs);
}

SystemObject* TextFile::clone() const
{
	return new TextFile(*this);
}
