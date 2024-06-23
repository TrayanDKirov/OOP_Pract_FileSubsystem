#include "ScriptFile.h"

void ScriptFile::loadFromDataFile(std::ifstream& ifs)
{
	SystemObject::loadData(ifs);

	this->arrOfCommands.readFromDataFile(ifs);
}

void ScriptFile::saveInDataFile(std::ofstream& ofs) const
{

	EnumClasses::TypeOfObject type = EnumClasses::TypeOfObject::scriptFile;
	ofs.write(reinterpret_cast<const char*>(&type), sizeof(type));

	SystemObject::saveData(ofs);

	this->arrOfCommands.wrireInDataFile(ofs);
}

SystemObject* ScriptFile::clone() const
{
	return new ScriptFile(*this);
}
