#include "SystemObjectContainer.h"

void SystemObjectContainer::resize(size_t newCapacity)
{
	
}

void SystemObjectContainer::moveFrom(SystemObjectContainer&& other) noexcept
{
	this->data = other.data;
	other.data = nullptr;

	this->size = other.size;
	other.size = 0;

	this->capacity = other.capacity;
	other.capacity = 0;
}
void SystemObjectContainer::copyFrom(const SystemObjectContainer& other)
{
	this->capacity = other.capacity;
	this->size = other.size;

	this->data = new SystemObject* [this->capacity] { nullptr };

	for (size_t i = 0; i < this->size; i++)
	{
		this->data[i] = other.data[i]->clone();
	}
}
void SystemObjectContainer::free() noexcept
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

SystemObjectContainer::SystemObjectContainer()
{
	this->size = 0;
	this->capacity = 8;
	this->data = new SystemObject* [this->capacity] { nullptr };
}

SystemObjectContainer::SystemObjectContainer(const SystemObjectContainer& other)
{
	copyFrom(other);
}
SystemObjectContainer& SystemObjectContainer::operator=(const SystemObjectContainer& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

SystemObjectContainer::SystemObjectContainer(SystemObjectContainer&& other) noexcept
{
	moveFrom(std::move(other));
}
SystemObjectContainer& SystemObjectContainer::operator=(SystemObjectContainer&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

SystemObjectContainer::~SystemObjectContainer() noexcept
{
	free();
}

void SystemObjectContainer::add(SystemObject* item)
{
	if (this->size == this->capacity)
	{
		resize(this->capacity * 2);
	}

	this->data[this->size++] = item;
}
void SystemObjectContainer::remove()
{
	delete this->data[this->size - 1];
	this->data[this->size - 1] = nullptr;

	this->size--;

	if (this->size == this->capacity / 4)
	{
		resize(this->capacity / 2);
	}
}
void SystemObjectContainer::remove(size_t index)
{
	for (size_t i = index; i < this->size - 1; i++)
	{
		std::swap(this->data[i], this->data[i + 1]);
	}

	remove();
}

const SystemObject* SystemObjectContainer::operator[](size_t index) const
{
	if (index >= this->capacity)
	{
		throw std::out_of_range("Index in SystemObjectConatiner::operator[] is inbvalid. ");
	}

	return this->data[index];
}
SystemObject* SystemObjectContainer::operator[](size_t index)
{
	if (index >= this->capacity)
	{
		throw std::out_of_range("Index in SystemObjectConatiner::operator[] is inbvalid. ");
	}

	return this->data[index];
}