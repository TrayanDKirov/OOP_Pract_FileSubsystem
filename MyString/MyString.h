#pragma once
#include <iostream>
#include <fstream>
#pragma warning(disable:4996)

namespace GLOBAL_CONSTS
{
	constexpr size_t MAX_BUFFER_SIZE = 1024;
}

class MyString
{
	char* data;
	size_t len;
	size_t capacity;

	void moveFrom(MyString&& other);
	void copyFrom(const MyString& other);
	void free();

	void resize(size_t newCap);

public:

	MyString();
	MyString(size_t len);
	MyString(const char* str);

	MyString(const MyString& other);
	MyString& operator=(const MyString& other);

	MyString(MyString&& other) noexcept;
	MyString& operator=(MyString&& other) noexcept;

	~MyString() noexcept;

	size_t getLen() const;
	size_t getCapacity() const;
	const char* c_str() const;

	MyString& operator+=(const MyString& other);
	MyString& operator+=(char ch);

	char& operator[](size_t index);
	char operator[](size_t index) const;

	friend MyString operator+(const MyString& lhs, const MyString& rhs);
	friend std::ostream& operator<<(std::ostream& os, const MyString& str);
	friend std::istream& operator>>(std::istream& is, MyString& str);

	MyString subStr(size_t from, size_t length) const;

	void readFromBinaryStream(std::ifstream& ifs);
	void readFromBinaryFile(const MyString& filePath);
};

bool operator==(const MyString& lhs, const MyString& rhs);
bool operator!=(const MyString& lhs, const MyString& rhs);
bool operator<(const MyString& lhs, const MyString& rhs);
bool operator<=(const MyString& lhs, const MyString& rhs);
bool operator>(const MyString& lhs, const MyString& rhs);
bool operator>=(const MyString& lhs, const MyString& rhs);