#include "File.h"

void File::savePathToDataFile(std::ofstream& ofs) const
{
	this->pathToFile.writeInDataFile(ofs);
}

void File::setPathToFile(const MyString& pathToFile)
{
	this->pathToFile = pathToFile;
}
