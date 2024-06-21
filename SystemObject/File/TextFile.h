#pragma once
#include "File.h"

class TextFile : public File
{

	MyString dataFromFile;

	void saveFile(std::ostream& os) const;
	void saveFile() const;

public:

	void loadFromDataFile(std::ifstream& ifs) override;
	void saveInDataFile(std::ofstream& ofs) const override;

	SystemObject* clone() const;

	~TextFile() override = default;

};