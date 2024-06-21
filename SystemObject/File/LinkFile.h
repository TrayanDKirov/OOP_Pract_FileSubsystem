#pragma once
#include "File.h"

class LinkFile : public File
{
	MyString pathInDirectory;

	void saveFile(std::ostream& os) const;
	void saveFile() const;

public:

	void loadFromDataFile(std::ifstream& ifs) override;
	void saveInDataFile(std::ofstream& ofs) const override;

	SystemObject* clone() const;

	~LinkFile() override = default;

};