#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <limits>

class ScalarConverter
{
public:
    ScalarConverter();
    ScalarConverter(const ScalarConverter &cpy);
    ~ScalarConverter();
    ScalarConverter &operator=(const ScalarConverter &rhs);

    static void convert(const std::string &literal);
};

#endif