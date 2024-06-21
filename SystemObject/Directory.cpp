#include "Directory.h"

SystemObject* Directory::clone() const 
{
	return new Directory(*this);
}

void Directory::loadFromDataFile(std::ifstream& ifs)
{
	this->name.readFromDataFile(ifs);
	this->creationDate.loadFromDataFile(ifs);
	this->modificationDate.loadFromDataFile(ifs);

	this->arrOfSystemObjects.loadFromDataFile(ifs);
}

void Directory::saveInDataFile(std::ofstream& ofs) const
{
	this->name.writeInDataFile(ofs);
	this->creationDate.saveInDataFile(ofs);
	this->modificationDate.saveInDataFile(ofs);

	this->arrOfSystemObjects.saveInDataFile(ofs);
}
