#include <iostream>

int main()
{
	try
	{

	}
	catch (std::invalid_argument& ex)
	{
		std::cout << ex.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown exeption thrown. " << std::endl;
	}
}