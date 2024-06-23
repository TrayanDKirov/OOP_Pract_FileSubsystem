#pragma once
#include "../Command.h"
#include "../../System/PathInSystem.h"
#include "../../SystemObject/File/File.h"

class RemoveFile : public Command
{
	PathInSystem path;

public:

	RemoveFile() = default;

	Command* clone() const override;
	void execute(FileSubsystem& system) const override;

	void saveInDataFile(std::ofstream& ofs) const override;
	void loadFromDataFile(std::ifstream& ifs) override;

	void loadFromStrStream(std::stringstream& strStream) override;


	~RemoveFile() override = default;
};