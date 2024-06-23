#include "SystemObject.h"

void SystemObject::loadData(std::ifstream& ifs)
{
	this->name.readFromDataFile(ifs);
	this->creationDate.loadFromDataFile(ifs);
	this->modificationDate.loadFromDataFile(ifs);
}

void SystemObject::saveData(std::ofstream& ofs) const
{
	this->name.writeInDataFile(ofs);
	this->creationDate.saveInDataFile(ofs);
	this->modificationDate.saveInDataFile(ofs);
}

void SystemObject::setParentDirecory(Directory* parentDirectory)
{
	this->parentDirectory = parentDirectory;
}

void SystemObject::setName(const MyString& name)
{
	this->name = name;
}

void SystemObject::setCreationDate(const DateAndTime& date)
{
	this->creationDate = date;
}

void SystemObject::setModificationDate(const DateAndTime& date)
{
	this->modificationDate = date;
}

void SystemObject::printInfo(std::ostream& os) const
{
	os << modificationDate << ' ' << name;
}

Directory* SystemObject::getParentDirecory()
{
	return this->parentDirectory;
}

const Directory* SystemObject::getParentDirecory() const
{
	return this->parentDirectory;
}

const MyString& SystemObject::getName() const
{
	return this->name;
}
