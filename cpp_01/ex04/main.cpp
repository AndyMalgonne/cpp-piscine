#include <iostream>
#include <string>
#include <fstream>

int main(int ac, char **av)
{
	if(ac != 4)
	{
		std::cout << "Usage: ./ex04 <filename> <s1> <s2>" << std::endl;
		return 1;
	}
	if(av[2][0] == '\0' || av[3][0] == '\0')
	{
		std::cout << "Error: s1 and s2 cannot be empty." << std::endl;
		return 1;
	}
	std::string filename = av[1];
	std::string s1 = av[2];
	std::string s2 = av[3];
	std::ifstream infile(filename.c_str());
	if (!infile.is_open())
	{
		std::cout << "Error: Could not open file " << filename << std::endl;
		return 1;
	}
	std::ofstream output((filename + ".replace").c_str());
	if (!output.is_open())
	{
		std::cout << "Error: Could not create output file." << std::endl;
		return 1;
	}

	while(infile.good())
	{
		std::string line;
		std::getline(infile, line);
		size_t pos = 0;
		while ((pos = line.find(s1, pos)) != std::string::npos)
		{
			line.replace(pos, s1.length(), s2);
			pos += s2.length();
		}
		output << line << std::endl;
	}
	infile.close();
	output.close();

	std::cout << "File " << filename << " has been replaced with " << filename + ".replace" << std::endl;

}