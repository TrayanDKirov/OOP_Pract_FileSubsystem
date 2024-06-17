#pragma once
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
};