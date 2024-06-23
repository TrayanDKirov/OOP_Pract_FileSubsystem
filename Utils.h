#pragma once
#include "MyString/MyString.h"

namespace GLOBAL_CONSTS
{
	constexpr size_t NUMBER_OF_COMMANDS = 11;
	const size_t LEN_OF_SCRIPT_EXT = 3;
	const size_t LEN_OF_TEXT_EXT = 3;
	const char COMMAND_SEP = ' ';

	const char SEP_IN_PATH = '/';
}

namespace EnumClasses
{
	enum class TypeOfCommand : unsigned char
	{
		cd,
		echo,
		exec,
		exit,
		find,
		ls,
		mkdir,
		pwd,
		rm,
		rmdir,
		touch
	};

	enum class TypeOfObject : unsigned char
	{
		directory,
		file,
		textFile,
		scriptFile,
		linkFile
	};
}

struct FileExtentions
{
	MyString arr[3];
	size_t numberOfExtentions = 3;

	FileExtentions()
	{
		this->arr[0] = ".txt";
		this->arr[1] = ".sh";
		this->arr[2] = ".lnk";
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

	EnumClasses::TypeOfObject getTypeOfFile(const MyString& ext) const
	{ 
		for (size_t i = 0; i < this->numberOfExtentions; i++)
		{
			if (arr[i] == ext)
			{
				return (EnumClasses::TypeOfObject)(i + (size_t)(EnumClasses::TypeOfObject::textFile));
			}
		}

		throw std::logic_error("Invalid extention of file. FileExtentions::getTypeOfFile");
	}

};

