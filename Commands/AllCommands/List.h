#pragma once
#include "../Command.h"
#include "../../System/PathInSystem.h"

class List : public Command
{
	PathInSystem path;

public:

	List() = default;

	Command* clone() const override;
	void execute(FileSubsystem& system) const override;

	void saveInDataFile(std::ofstream& ofs) const override;
	void loadFromDataFile(std::ifstream& ifs) override;

	void loadFromStrStream(std::stringstream& strStream) override;


	~List() override = default;
};