#include <iostream>

int main()
{
	std::string variable = "HI THIS IS BRAIN";
	std::string *variable2 = &variable;
	std::string &variable3 = variable;

	std::cout << &variable << std::endl;
	std::cout << variable2 << std::endl;
	std::cout << &variable3 << std::endl;

	std::cout << variable << std::endl;
	std::cout << *variable2 << std::endl;
	std::cout << variable3 << std::endl;
}