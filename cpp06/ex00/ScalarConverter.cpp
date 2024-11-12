#include "ScalarConverter.hpp"

bool    isInf(const std::string& input){
    if (input == "inf" || input == "-inf" || input == "inff" || input == "-inff")
        return true;
    else
        return false;
}

std::string get_type(const std::string& input){
    std::string result;

    if (isInf(input))
        result = "double";
    else if (input.length() == 1 && ((input[0] >= 65 && input[0] <= 90) || (input[0] >= 97 && input[0] < 122))){
            result = "char";
    }
    else if (input.find('.') != std::string::npos || input.find("inf") != std::string::npos || input == "nan")
    {
        if (input.find('f') != std::string::npos)
            result = "float";
        else
            result = "double";
    }
    else if (atoi(input.c_str()) || input == "0")
        result = "int";
    else
        result = "error";
    return result;
}

bool isValid(const std::string& input, const std::string& type){
    int dot;
    int f;

    dot = 0;
    f = 0;
    if (isInf(input) || type == "char" || input == "nan")
        return true;
    for (size_t i  = 0; i < input.size(); ++i){
        if (i == 0 && input[i] == '-')
            continue;
        if (!isdigit(input[i]) && input[i] != '.' && input[i] != 'f')
            return false;
        else if (input[i] == '.')
        {
            dot++;
            if (dot >= 2 || i == 0 || i == input.size() - 1)
                return false;
        }
        else if (input[i] == 'f')
        {
            f++;
            if (f >= 2)
                return false;
        }
    }
    return true;
}

void ScalarConverter::convert(std::string input){
    char    c;
    int     i;
    double  d;
    float   f;

    c = 0;
    i = 0;
    d = 0;
    f = 0;

    std::string type = get_type(input);

    if (isValid(input, type) == false || type == "error"){
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return ;
    }

    if ((type == "float" && input[input.size() - 1] == 'f') || input == "inff" || input == "-inff"){
        std::string ret;

        for (size_t i = 0; i < input.size() - 1; i++){
            ret += input[i]; 
        }
        input = ret;
    }
    std::stringstream ss(input);

    if (type == "char")
    {
        ss >> c;
        i = static_cast<int>(c);
        f = static_cast<float>(c);
        d = static_cast<double>(c);
    }
    else if (type == "double" || type == "int")
    {
        ss >> d;
        c = static_cast<char>(d);
        i = static_cast<int>(d);
        f = static_cast<float>(d);
    }
    else if (type == "float")
    {
        ss >> f;
        c = static_cast<char>(f);
        i = static_cast<int>(f);
        d = static_cast<double>(f);
    }
    else
        std::cout << "error" << std::endl;
    if ((i >= 0 && i <= 255) && ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')|| (c >= 32 &&  c <= 126)))    
        std::cout << "char: '" << c << "'" << std::endl;
    else
    {
        ss >> d;
        if (d != d || d < 0 || d > 255)
            std::cout << "char: impossible" << std::endl;
        else
            std::cout << "char: Non displayable" << std::endl;
    }

    if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max() || d != d)
        std::cerr << "int: impossible" << std::endl;
    else
        std::cout << "int: " << i << std::endl;

    if (static_cast<float>(i) == f)
        std::cout << "float: " << f << ".0f" << std::endl;
    else
        std::cout << "float: " << f << "f" << std::endl;

    std::cout << "double: " << d << std::endl;
}