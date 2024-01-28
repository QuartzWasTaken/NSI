#include <iostream>

void Log(const char*);
int Ask();

int main()
{
	char* ptr = new char[8];
	memset(ptr, 0, 8);
	std::cout << *ptr;

	delete[8] ptr;
	
}