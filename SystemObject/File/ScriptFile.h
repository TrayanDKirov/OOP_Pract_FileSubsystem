#pragma once
#include "File.h"
#include "../../Commands/CommandContainer.h"

class ScriptFile : public File
{
	CommandContainer arrOfCommands;

public:

	void loadFromDataFile(std::ifstream& ifs) override;
	void saveInDataFile(std::ofstream& ofs) const override;

	SystemObject* clone() const;

	~ScriptFile() override = default;

};