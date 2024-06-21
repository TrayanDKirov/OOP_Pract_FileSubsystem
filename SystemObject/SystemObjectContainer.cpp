#include "SystemObjectContainer.h"
#include "SystemObjectFactory.h"

static unsigned getNextPowerOfTwo(unsigned n)
{
	unsigned powerOfTwo = 1;

	while (powerOfTwo <= n)
	{
		powerOfTwo <<= 1;
	}

	return powerOfTwo;
}

static size_t getCapacityNeeded(size_t size)
{
	return std::max(getNextPowerOfTwo(size), 8u);
}

void SystemObjectContainer::resize(size_t newCapacity)
{
	if (newCapacity < this->size)
	{
		throw std::length_error("NewCapacity in SystemObjectContainer::resize() is less than size");
	}

	SystemObject** newArr = new SystemObject* [newCapacity] { nullptr };
	for (size_t i = 0; i < this->size; i++)
	{
		newArr[i] = this->data[i];
	}

	delete[] this->data;
	this->data = newArr;
	this->capacity = newCapacity;
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
	if (index >= this->size)
	{
		throw std::out_of_range("Index in SystemObjectConatiner::operator[] is inbvalid. ");
	}

	return this->data[index];
}
SystemObject* SystemObjectContainer::operator[](size_t index)
{
	if (index >= this->size)
	{
		throw std::out_of_range("Index in SystemObjectConatiner::operator[] is invalid. ");
	}

	return this->data[index];
}

void SystemObjectContainer::loadFromDataFile(std::ifstream& ifs)
{
	free();

	ifs.read(reinterpret_cast<char*>(&size), sizeof(this->size));

	this->capacity = getCapacityNeeded(this->size);

	this->data = new SystemObject* [this->capacity];

	SystemObjectFactory factory = SystemObjectFactory::getInstance();
	for (size_t i = 0; i < this->size; i++)
	{
		this->data[i] = factory.createObject(ifs);
	}
}

void SystemObjectContainer::saveInDataFile(std::ofstream& ofs) const
{
	ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));

	for (size_t i = 0; i < this->size;i++)
	{
		this->data[i]->saveToDataFile(ofs);
	}
}

size_t SystemObjectContainer::getSize() const
{
	return this->size;
}
size_t SystemObjectContainer::getCapacity() const
{
	return this->capacity;
}