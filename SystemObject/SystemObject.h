#pragma once
#include <iostream>
#include "../MyString/MyString.h"
#include "../DateAndTime/DateAndTime.h"

class Directory;

class SystemObject
{

protected:

	MyString name;
	DateAndTime creationDate;
	DateAndTime modificationDate;

	Directory* parentDirectory = nullptr;

	void loadData(std::ifstream& ifs);
	void saveData(std::ofstream& ofs) const;

public:

	void setParentDirecory(Directory* parentDirectory);
	void setName(const MyString& name);
	void setCreationDate(const DateAndTime& date);
	void setModificationDate(const DateAndTime& date);

	void printInfo(std::ostream& os) const;

	Directory* getParentDirecory();
	const Directory* getParentDirecory() const;
	const MyString& getName() const;

	virtual SystemObject* clone() const = 0;

	virtual void loadFromDataFile(std::ifstream& ifs) = 0;
	virtual void saveInDataFile(std::ofstream& ofs) const = 0;


	virtual ~SystemObject() = default;
};