#include "ScriptFile.h"

void ScriptFile::saveFile(std::ostream& os) const
{
	this->arrOfCommands.wrireCommandsInStream(os);
}

void ScriptFile::saveFile() const
{
	std::ofstream ofs(this->pathToFile.c_str(), std::ios::out | std::ios::trunc);
	if (!ofs.is_open())
	{
		throw std::runtime_error("File did not open in LinkFile::saveFile()");
	}

	saveFile(ofs);
	ofs.close();
}

void ScriptFile::loadFromDataFile(std::ifstream& ifs)
{

}

void ScriptFile::saveInDataFile(std::ofstream& ofs) const
{
	saveFile();

	TypeOfObject type = TypeOfObject::file;

	ofs.write(reinterpret_cast<const char*>(&type), sizeof(type));
	File::savePathToDataFile(ofs);
}

SystemObject* ScriptFile::clone() const
{
	return new ScriptFile(*this);
}
