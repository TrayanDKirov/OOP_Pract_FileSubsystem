#pragma once
#include "../SystemObject.h"
#include "../../Utils.h"

class File : public SystemObject
{
protected:

	MyString pathToFile;

public:

	void savePathToDataFile(std::ofstream& ofs) const;

	void setPathToFile(const MyString& pathToFile);

	~File() override = default;
};