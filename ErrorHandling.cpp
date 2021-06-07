#include "ErrorHandling.h"
int errorHandle(const int& input)
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//std::cout << "Invalid input! \n";
		return -1;
	}
	else
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return input;
	}
}

char errorHandle(const char& input)
{
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		//std::cout << "Invalid input";
		return '1';
	}
	else
	{
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return input;
	}
}