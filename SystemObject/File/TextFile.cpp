#include "TextFile.h"

void TextFile::loadFromDataFile(std::ifstream& ifs)
{
	SystemObject::loadData(ifs);

	this->dataFromFile.readFromDataFile(ifs);
}

void TextFile::saveInDataFile(std::ofstream& ofs) const
{
	EnumClasses::TypeOfObject type = EnumClasses::TypeOfObject::file;
	ofs.write(reinterpret_cast<const char*>(&type), sizeof(type));

	SystemObject::saveData(ofs);
	this->dataFromFile.writeInDataFile(ofs);
}

SystemObject* TextFile::clone() const
{
	return new TextFile(*this);
}
