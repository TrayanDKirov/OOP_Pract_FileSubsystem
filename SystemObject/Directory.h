#pragma once
#include "SystemObject.h"
#include "SystemObjectContainer.h"
#include "../Utils.h"

class Directory : public SystemObject, public SystemObjectContainer
{

public: 

	SystemObject* clone() const override;

	void loadFromDataFile(std::ifstream& ifs) override;
	void saveInDataFile(std::ofstream& ofs) const override;

	void printInfoOfObjects(std::ostream& os) const;

	~Directory() override = default;
};