#pragma once
#include "File.h"
#include "../../System/PathInSystem.h"

class LinkFile : public File
{
	PathInSystem pathInDirectory;

public:

	LinkFile() = default;

	void loadFromDataFile(std::ifstream& ifs) override;
	void saveInDataFile(std::ofstream& ofs) const override;

	SystemObject* clone() const;

	~LinkFile() override = default;
};