#pragma once
#include <fstream>
#include "SystemObject.h"

class SystemObjectContainer
{
	SystemObject** data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void resize(size_t newCapacity);

	void moveFrom(SystemObjectContainer&& other) noexcept;
	void copyFrom(const SystemObjectContainer& other);
	void free() noexcept;

public:

	SystemObjectContainer();

	SystemObjectContainer(const SystemObjectContainer& other);
	SystemObjectContainer& operator=(const SystemObjectContainer& other);

	SystemObjectContainer(SystemObjectContainer&& other) noexcept;
	SystemObjectContainer& operator=(SystemObjectContainer&& other) noexcept;

	~SystemObjectContainer() noexcept;

	void add(SystemObject* item);
	void remove();
	void remove(size_t index);

	const SystemObject* operator[](size_t index) const;
	SystemObject* operator[](size_t index);

	void loadFromDataFile(std::ifstream& ifs, Directory* parentDirectory);
	void saveInDataFile(std::ofstream& ofs) const;

	SystemObject* getObjectByName(const MyString& name);
	size_t getIndexOfObject(SystemObject* item) const;

	void setItem(const MyString& name, const DateAndTime& date, size_t index);
	void setItem(const MyString& name, const DateAndTime& creationDate, const DateAndTime& modificationDate, size_t index);
	void printInfoAboutObjects(std::ostream& os) const;

	size_t getSize() const;
	size_t getCapacity() const;
};