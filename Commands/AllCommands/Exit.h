#pragma once
#include "../Command.h"

class Exit : public Command
{

public:

	Exit() = default;

	Command* clone() const override;
	void execute(FileSubsystem& system) const override;

	void saveInDataFile(std::ofstream& ofs) const override;
	void loadFromDataFile(std::ifstream& ifs) override;

	void loadFromStrStream(std::stringstream& strStream) override;


	~Exit() override = default;
};