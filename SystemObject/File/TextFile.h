#pragma once
#include "File.h"

class TextFile : public File
{

	MyString dataFromFile;

public:

	void loadFromDataFile(std::ifstream& ifs) override;
	void saveInDataFile(std::ofstream& ofs) const override;

	SystemObject* clone() const;

	~TextFile() override = default;

};