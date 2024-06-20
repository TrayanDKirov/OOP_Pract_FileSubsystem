#include "MyString.h"

static unsigned getNextPowerOfTwo(unsigned n)
{
	unsigned powerOfTwo = 1;

	while (powerOfTwo <= n)
	{
		powerOfTwo <<= 1;
	}

	return powerOfTwo;
}
static size_t getCapacityNeeded(size_t len)
{
	return std::max(getNextPowerOfTwo(len + 1), 16u);
}

static size_t getSizeOfFile(std::ifstream& ifs)
{
	size_t currPos = ifs.tellg();
	ifs.seekg(0, std::ios::end);

	size_t sizeOfFile = ifs.tellg();
	ifs.seekg(currPos);

	return sizeOfFile;
}

static void myStrNCat(char* dest, const char* source, size_t len)
{
	size_t index = 0;
	while (len != 0)
	{
		dest[index] = source[index++];

		len--;
	}
	dest[index] = '\0';
}

void MyString::moveFrom(MyString&& other)
{
	this->len = other.len;
	other.len = 0;

	this->capacity = other.capacity;
	other.capacity = 0;

	this->data = other.data;
	other.data = nullptr;
}
void MyString::copyFrom(const MyString& other)
{
	this->len = other.len;
	this->capacity = other.capacity;

	this->data = new char[this->capacity + 1];
	std::strcpy(this->data, other.data);
}
void MyString::free()
{
	delete[] this->data;
	this->data = nullptr;

	this->len = 0; 
	this->capacity = 0;
}

void MyString::resize(size_t newCap)
{
	char* newData = new char[newCap + 1];

	for (size_t i = 0; i <= this->len; i++)
	{
		newData[i] = this->data[i];
	}

	delete[] this->data;
	this->data = newData;
	this->capacity = newCap;
}

MyString::MyString() : MyString("") { }
MyString::MyString(size_t len)
{
	this->len = len;

	this->capacity = getCapacityNeeded(this->len);

	this->data = new char[this->capacity + 1];
}
MyString::MyString(const char* str)
{
	if (!str)
	{
		throw std::invalid_argument("Nullptr in constructor. ");
	}

	this->len = std::strlen(str);

	this->capacity = getNextPowerOfTwo(this->len);

	this->data = new char[this->capacity + 1];
	std::strcpy(this->data, str);
}

MyString::MyString(const MyString& other)
{
	copyFrom(other);
}
MyString& MyString::operator=(const MyString& other)
{
	if (this != &other)
	{
		free();
		copyFrom(other);
	}
	return *this;
}

MyString::MyString(MyString&& other) noexcept
{
	moveFrom(std::move(other));
}
MyString& MyString::operator=(MyString&& other) noexcept
{
	if (this != &other)
	{
		free();
		moveFrom(std::move(other));
	}
	return *this;
}

MyString::~MyString() noexcept
{
	free();
}

size_t MyString::getLen() const
{
	return this->len;
}
size_t MyString::getCapacity() const
{
	return this->capacity - 1;
}
const char* MyString::c_str() const
{
	return this->data;
}

MyString& MyString::operator+=(const MyString& other)
{
	size_t newLen = this->len + other.getLen();

	if (newLen + 1 > this->capacity)
	{
		resize(getCapacityNeeded(newLen));
	}
	
	std::strncat(this->data, other.data, other.getLen() + 1);
	this->len = newLen;

	return *this;
}
MyString& MyString::operator+=(char ch)
{
	if (this->len == this->capacity)
	{
		resize(getCapacityNeeded(this->len + 1));
	}

	this->data[this->len] = ch;

	this->len++;
	this->data[this->len] = '\0';

	return *this;
}

char& MyString::operator[](size_t index)
{
	if (index >= this->len)
	{
		throw std::invalid_argument("Invalid index. ");
	}

	return this->data[index];
}
char MyString::operator[](size_t index) const
{
	if (index >= this->len)
	{
		throw std::invalid_argument("Invalid index. ");
	}

	return this->data[index];
}

MyString operator+(const MyString& lhs, const MyString& rhs)
{
	MyString result(lhs.getLen() + rhs.getLen());
	result += lhs;
	result += rhs;

	return result;
}

std::ostream& operator<<(std::ostream& os, const MyString& str)
{
	return os << str.data;
}

std::istream& operator>>(std::istream& is, MyString& str)
{
	char buffer[GLOBAL_CONSTS::MAX_BUFFER_SIZE];
	is >> buffer;

	size_t bufferSize = std::strlen(buffer);
	if (bufferSize >= str.capacity)
	{
		str.resize(getCapacityNeeded(bufferSize));
	}

	std::strcpy(str.data, buffer);
	str.len = bufferSize;

	return is;
}

MyString MyString::subStr(size_t from, size_t length) const
{
	if (from + length - 1 >= getLen())
	{
		throw std::length_error("Invalid lenght or beginIndex in MyString::subStr()");
	}

	MyString result(length + 1);

	myStrNCat(result.data, this->data + from, length);

	return result;
}

void MyString::readFromBinaryFile(const MyString& filePath)
{
	std::ifstream file(filePath.c_str(), std::ios::binary | std::ios::in);
	if (!file.is_open())
	{
		throw std::runtime_error("File did not open(In MyString::readFromBinaryFile()). ");
	}

	readFromBinaryStream(file);
	file.close();
}


void MyString::readFromBinaryStream(std::ifstream& ifs)
{
	size_t sizeToRead;
	ifs.read(reinterpret_cast<char*>(sizeToRead), sizeof(sizeToRead));
	resize(getCapacityNeeded(sizeToRead));

	ifs.read(reinterpret_cast<char*>(this->data), sizeToRead * sizeof(char));

	this->len = sizeToRead;
	this->data[this->len] = '\0';
}

bool operator==(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) == 0;
}
bool operator!=(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) != 0;
}
bool operator<(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) < 0;
}
bool operator<=(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) <= 0;
}
bool operator>(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) > 0;
}
bool operator>=(const MyString& lhs, const MyString& rhs)
{
	return std::strcmp(lhs.c_str(), rhs.c_str()) >= 0;
}