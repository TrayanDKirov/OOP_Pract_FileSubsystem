#include <iostream>
#include "Sysytem/FileSubsystem.h"

int main()
{
	FileSubsystem system;

	try
	{
		system.run("data.dat");
	}
	catch (std::exception& ex)
	{
		std::cout << ex.what();
	}
	catch (const char* str)
	{
		std::cout << str;
	}
	catch (...)
	{

	}
}