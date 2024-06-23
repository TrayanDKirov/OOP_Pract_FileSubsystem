#pragma once
#include "Command.h"

class CommandContainer
{
	Command** data = nullptr;
	size_t size = 0;
	size_t capacity = 0;

	void resize(size_t newCapacity);

	void moveFrom(CommandContainer&& other) noexcept;
	void copyFrom(const CommandContainer& other);
	void free() noexcept;

public:

	CommandContainer();

	CommandContainer(const CommandContainer& other);
	CommandContainer& operator=(const CommandContainer& other);

	CommandContainer(CommandContainer&& other) noexcept;
	CommandContainer& operator=(CommandContainer&& other) noexcept;

	~CommandContainer() noexcept;

	void add(Command* item);
	void remove();
	void remove(size_t index);

	const Command* operator[](size_t index) const;
	Command* operator[](size_t index);

	void wrireInDataFile(std::ofstream& ofs) const;
	void readFromDataFile(std::ifstream& ifs);

	size_t getSize() const;
	size_t getCapacity() const;
};