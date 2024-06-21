#include "CommandContainer.h"

void CommandContainer::resize(size_t newCapacity)
{
	if (newCapacity < this->size)
	{
		throw std::length_error("NewCapacity in SystemObjectContainer::resize() is less than size");
	}

	Command** newArr = new Command* [newCapacity] { nullptr };
	for (size_t i = 0; i < this->size; i++)
	{
		newArr[i] = this->data[i];
	}

	delete[] this->data;
	this->data = newArr;
	this->capacity = newCapacity;
}

void CommandContainer::moveFrom(CommandContainer&& other) noexcept
{
	this->data = other.data;
	other.data = nullptr;

	this->size = other.size;
	other.size = 0;

	this->capacity = other.capacity;
	other.capacity = 0;
}
void CommandContainer::copyFrom(const CommandContainer& other)
{
	this->capacity = other.capacity;
	this->size = other.size;

	this->data = new Command* [this->capacity] { nullptr };

	for (size_t i = 0; i < this->size; i++)
	{
		this->data[i] = other.data[i]->clone();
	}
}
void CommandContainer::free() noexcept
{
	for (size_t i = 0; i < this->size; i++)
	{
		delete this->data[i];
	}
	delete[] this->data;

	this->data = nullptr;
	this->size = 0;
	this->capacity = 0;
}

CommandContainer::CommandContainer()
{
	this->size = 0;
	this->capacity = 8;
	this->data = new Command* [this->capacity] { nullptr };
}

CommandContainer::CommandContainer(const CommandContainer& other)
{
	copyFrom(other);
}
CommandContainer& CommandContainer::operator=(const CommandContainer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

CommandContainer::CommandContainer(CommandContainer&& other) noexcept
{
	moveFrom(std::move(other));
}
CommandContainer& CommandContainer::operator=(CommandContainer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

CommandContainer::~CommandContainer() noexcept
{
	free();
}

void CommandContainer::add(Command* item)
{
	if (this->size == this->capacity)
	{
		resize(this->capacity * 2);
	}

	this->data[this->size++] = item;
}
void CommandContainer::remove()
{
	delete this->data[this->size - 1];
	this->data[this->size - 1] = nullptr;

	this->size--;

	if (this->size == this->capacity / 4)
	{
		resize(this->capacity / 2);
	}
}
void CommandContainer::remove(size_t index)
{
	for (size_t i = index; i < this->size - 1; i++)
	{
		std::swap(this->data[i], this->data[i + 1]);
	}

	remove();
}

const Command* CommandContainer::operator[](size_t index) const
{
	if (index >= this->size)
	{
		throw std::out_of_range("Index in SystemObjectConatiner::operator[] is inbvalid. ");
	}

	return this->data[index];
}
Command* CommandContainer::operator[](size_t index)
{
	if (index >= this->size)
	{
		throw std::out_of_range("Index in SystemObjectConatiner::operator[] is inbvalid. ");
	}

	return this->data[index];
}

void CommandContainer::wrireCommandsInStream(std::ostream& os) const
{
	for (size_t i = 0; i < this->size; i++)
	{
		this->data[i]->writeInTextFile(os);
		os << std::endl;
	}
}

size_t CommandContainer::getSize() const
{
	return this->size;
}
size_t CommandContainer::getCapacity() const
{
	return this->capacity;
}