#include "MyString/MyString.h"

enum class TypeOfObject : unsigned char
{
	directory = 0,
	file = 1,
	textFile = 2,
	scriptFile = 3,
	linkFile = 4
};

struct FileExtentions
{
	MyString arr[3];
	size_t numberOfExtentions = 3;

	FileExtentions()
	{
		this->arr[0] = "txt";
		this->arr[1] = ".sh";
		this->arr[2] = "lnk";
	}

	const MyString& operator[](size_t index) const
	{
		if (index >= this->numberOfExtentions)
		{
			throw std::invalid_argument("Index in FileExtensions::operator[]() cosnt is invalid");
		}

		return this->arr[index];
	}

	MyString& operator[](size_t index) 
	{
		if (index >= this->numberOfExtentions)
		{
			throw std::invalid_argument("Index in FileExtensions::operator[]() cosnt is invalid");
		}

		return this->arr[index];
	}

	TypeOfObject getTypeOfFile(const MyString& ext) const
	{ 
		for (size_t i = 0; i < this->numberOfExtentions; i++)
		{
			if (arr[i] == ext)
			{
				return (TypeOfObject)(i + (size_t)(TypeOfObject::textFile));
			}
		}

		throw std::logic_error("Invalid extention of file");
	}

} fileExtentions;

