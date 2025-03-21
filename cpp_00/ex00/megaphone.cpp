#include <iostream>
#include <string>

int main(int ac, char *av[])
{
	(void)av;
	if (ac == 1)
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
	for (int i = 1; i < ac; i++)
	{
		std::string	str = av[i];
		for (size_t y = 0; y < str.size() ; y++)
		{
			str[y] = toupper(str[y]);
		}
		std::cout << str;
	}
	std::cout << std::endl;
    return 0;
}
