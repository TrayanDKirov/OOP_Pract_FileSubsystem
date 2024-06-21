#pragma once
#include <iostream>
#include "../MyString/MyString.h"
#include "../DateAndTime/DateAndTime.h"

class SystemObject
{

protected:

	MyString name;
	DateAndTime creationDate;
	DateAndTime modificationDate;

public:

	virtual SystemObject* clone() const = 0;

	virtual void loadFromDataFile(std::ifstream& ifs) = 0;
	virtual void saveInDataFile(std::ofstream& ofs) const = 0;

	virtual ~SystemObject() = default;
};