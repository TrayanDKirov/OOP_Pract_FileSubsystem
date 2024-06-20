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

	virtual void loadFromDataFile(const MyString& filePath) = 0;
	virtual void saveToDataFile(const MyString& filePath) = 0;

	virtual ~SystemObject() = default;
};