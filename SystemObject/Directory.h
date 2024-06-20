#pragma once
#include "SystemObject.h"
#include "SystemObjectContainer.h"

class Directory : public SystemObject
{
	SystemObjectContainer arrOfSystemObjects;

public: 

	SystemObject* clone() const override;

	void loadFromDataFile(const MyString& filePath) override;
	void saveToDataFile(const MyString& filePath) override;


	~Directory() override = default;
};