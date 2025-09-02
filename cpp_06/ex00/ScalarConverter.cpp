#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{

}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter::~ScalarConverter()
{

}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return (*this);
}

int isPseudo(std::string const & str)
{
	if (str == "-inf" || str == "-inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
		return (1);
	}

	if (str == "+inf" || str == "+inff")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
		return (1);
	}

	if (str == "nan" || str == "nanf")
	{
		std::cout << "char: impossible" << std::endl;
		std::cout << "int: impossible" << std::endl;
		std::cout << "float: nanf" << std::endl;
		std::cout << "double: nan" << std::endl;
		return (1);
	}

	return (0);
}

bool isString(std::string const & str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!isdigit(str[i]))
			return false;
	}
	return true;
}

void toChar(std::string const & str)
{
    int value;

    if (str.length() == 1 && !std::isdigit(str[0]))
    {
        std::cout << "char: '" << str << "'" << std::endl;
        return;
    }

    char* end;
    float fvalue = std::strtof(str.c_str(), &end);

    if ((*end == '\0' || (*end == 'f' && *(end+1) == '\0')) && fvalue >= 0 && fvalue <= 127 && fvalue == static_cast<int>(fvalue))
    {
        value = static_cast<int>(fvalue);
        if (value >= 32 && value <= 126)
            std::cout << "char: '" << static_cast<char>(value) << "'" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
        return;
    }

    std::cout << "char: impossible" << std::endl;
}
// ...existing code...

void toInt(std::string const & str)
{
	if (str.length() == 1 && !isdigit(str[0]))
		std::cout << "int: " << static_cast<int>(str[0]) << std::endl;
	else if (((str[0] == '-' || str[1] == '+') && isdigit(str[1])) || isdigit(str[0]))
		std::cout << "int: " << static_cast<int>(std::atoi(str.c_str())) << std::endl;
	else
		std::cout << "int: impossible" << std::endl;
}

void toFloat(std::string const & str)
{
	char *end;
	float tmp = strtof(str.c_str(), &end);

	if (str.length() == 1 && !isdigit(str[0]))
		std::cout << "float: " << static_cast<float>(str[0]) << ".0f" << std::endl;
	else if ((str[0] == '-' || str[0] == '+') && isdigit(str[1]))
	{
		if (str.find('.') != std::string::npos && *end != 'f')
			std::cout << "float: " << str << "f" << std::endl;
		else if (str.find('.') != std::string::npos && *end == 'f')
			std::cout << "float: " << str << std::endl;
		else
			std::cout << "float: " << str << ".0f" << std::endl;
	}
	else if (isdigit(str[0]))
	{
		if (str.find('.') != std::string::npos && *end != 'f')
			std::cout << "float: " << str << "f" << std::endl;
		else if (str.find('.') != std::string::npos && *end == 'f')
			std::cout << "float: " << str << std::endl;
		else
		{
			if (*end == 'f')
				std::cout << "float: " << str.substr(0, str.length() - 1) << ".0f" << std::endl;
			else
				std::cout << "float: " << str << ".0f" << std::endl;
		}
	}
	else
		std::cout << "float: impossible" << std::endl;
	(void)tmp;
}

void toDouble(std::string const & str)
{
	char *end;
	float tmp = strtof(str.c_str(), &end);

	if (str.length() == 1 && !isdigit(str[0]))
		std::cout << "double: " << static_cast<double>(str[0]) << ".0" << std::endl;
	else if ((str[0] == '-' || str[0] == '+') && isdigit(str[1]))
	{
		if (str.find('.') != std::string::npos && *end != 'f')
			std::cout << "double: " << str << std::endl;
		else if (str.find('.') != std::string::npos && *end == 'f')
			std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
		else
			std::cout << "double: " << str << ".0" << std::endl;
	}
	else if (isdigit(str[0]))
	{
		if (str.find('.') != std::string::npos && *end != 'f')
			std::cout << "double: " << str << std::endl;
		else if (str.find('.') != std::string::npos && *end == 'f')
			std::cout << "double: " << str.substr(0, str.length() - 1) << std::endl;
		else
		{
			if (*end == 'f')
				std::cout << "double: " << str.substr(0, str.length() - 1) << ".0" << std::endl;
			else
				std::cout << "double: " << str << ".0" << std::endl;
		}
	}
	else
		std::cout << "double: impossible" << std::endl;
	(void)tmp;
}

void ScalarConverter::convert(std::string const & str)
{
	if (isPseudo(str))
		return;

	toChar(str);
	toInt(str);
	toFloat(str);
	toDouble(str);
}
