#pragma once
#include "../Command.h"
#include "../../System/PathInSystem.h"
#include "../../SystemObject/Directory.h"

class RemoveDirectory : public Command
{
	PathInSystem path;

public:

	RemoveDirectory() = default;

	Command* clone() const override;
	void execute(FileSubsystem& system) const override;

	void saveInDataFile(std::ofstream& ofs) const override;
	void loadFromDataFile(std::ifstream& ifs) override;

	void loadFromStrStream(std::stringstream& strStream) override;


	~RemoveDirectory() override = default;
};