#include <iostream>

void Log(const char* output)
{
	std::cout << output << std::endl;
}

int Ask()
{
	int input;
	std::cin >> input;
	return input;
}
