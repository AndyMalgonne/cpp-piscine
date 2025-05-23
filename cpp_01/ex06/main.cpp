#include "Harl.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Usage: ./harlFilter <level>" << std::endl;
		return 1;
	}

	Harl harl;
	int level = harl.getLevel(argv[1]);
	switch (level)
	{
		case 1:
			harl.complain("DEBUG");
			break;
		case 2:
			harl.complain("INFO");
			break;
		case 3:
			harl.complain("WARNING");
			break;
		case 4:
			harl.complain("ERROR");
			break;
		default:
			std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
			break;
	}
}
