#pragma once
#include "SystemObject.h"
#include "SystemObjectContainer.h"

class Directory : public SystemObject
{
	SystemObjectContainer arrOfSystemObjects;

public: 

	SystemObject* clone() const override;

	void loadFromDataFile(std::ifstream& ifs) override;
	void saveInDataFile(std::ofstream& ofs) const override;


	~Directory() override = default;
};