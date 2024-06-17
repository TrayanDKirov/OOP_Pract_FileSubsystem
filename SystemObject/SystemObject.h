#pragma once
#include "../MyString/MyString.h"
#include "../DateAndTime/DateAndTime.h"

class SystemObject
{

protected:

	MyString name;
	DateAndTime creationDate;
	DateAndTime modificationDate;

public:

	virtual SystemObject* clone() = 0;
	
	virtual ~SystemObject() = default;
};