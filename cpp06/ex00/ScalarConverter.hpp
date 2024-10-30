#ifndef SCALARCONVERTER_HPP
# define SCALARCONVERTER_HPP

#include <iostream>
#include <sstream>
#include <cctype>
#include <string>
#include <cstdlib>
#include <limits>

class ScalarConverter{
    private:
        ScalarConverter();
        ~ScalarConverter();
        ScalarConverter(const ScalarConverter &copy);
        ScalarConverter &operator=(const ScalarConverter &copy);
    public:
        static void convert(std::string input); 
};

#endif