#pragma once 
#include "../Command.h"
#include "../../System/PathInSystem.h"
#include "../../DateAndTime/CurrentDate.h"

class MakeDirectory : public Command
{
	MyString name;

public:

	MakeDirectory() = default;

	Command* clone() const override;
	void execute(FileSubsystem& system) const override;

	void saveInDataFile(std::ofstream& ofs) const override;
	void loadFromDataFile(std::ifstream& ifs) override;

	void loadFromStrStream(std::stringstream& strStream) override;


	~MakeDirectory() override = default;
};