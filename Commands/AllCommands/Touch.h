#pragma once
#include "../Command.h"
#include "../../System/PathInSystem.h"
#include "../../DateAndTime/CurrentDate.h"

class Touch : public Command
{
	MyString name;

public:

	Touch() = default;

	Command* clone() const override;
	void execute(FileSubsystem& system) const override;

	void saveInDataFile(std::ofstream& ofs) const override;
	void loadFromDataFile(std::ifstream& ifs) override;

	void loadFromStrStream(std::stringstream& strStream) override;


	~Touch() override = default;
};