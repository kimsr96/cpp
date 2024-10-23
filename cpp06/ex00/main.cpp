#include <iostream>
#include <cmath>
#include <limits>
#include <cstdlib>
#include <cstring>

int main(int argc, char **argv){
    char    *end;
    bool    is_float;
    double  d;

    if (argc != 2)
        return (1);

    d = std::strtod(argv[1], &end);
    //std::cout << d << std::endl;
    if ((*end != '\0' && *end != 'f') || end == argv[1])
    {
        std::cout << "char: impossible" << std::endl;
        std::cout << "int: impossible" << std::endl;
        std::cout << "float: impossible" << std::endl;
        std::cout << "double: impossible" << std::endl;
        return (1);
    }

    if (d < 0 || d > 255 || d != d)
        std::cerr << "char: impossible" << std::endl;
    else
    {
        char    c = static_cast<char>(d);
        if (c < 33 || c > 126)
            std::cout << "char: Non displayable" << std::endl;
        else
            std::cout << "char: '" << c << "'" << std::endl;
    }
    
    int i;
    if ((d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max()) || d != d){
        std::cerr << "int: impossible" << std::endl;
    }
    else{
        i = static_cast<int>(d);
        std::cout << "int: " << i << std::endl;
    }
    if (d != std::numeric_limits<double>::infinity() && d != -std::numeric_limits<double>::infinity()){
        if (d < std::numeric_limits<float>::lowest() || d > std::numeric_limits<float>::max())
            std::cerr << "float: impossible" << std::endl;
    }
    else{
        float   f = static_cast<float>(d);
        if (static_cast<float>(i) == f)
            std::cout << "float: " << f << ".0f" << std::endl;
        else
            std::cout << "float: " << f << "f" << std::endl;
    }

    if (d != std::numeric_limits<double>::infinity() && d != -std::numeric_limits<double>::infinity()){
        if (d < std::numeric_limits<double>::lowest() || d > std::numeric_limits<double>::max())
            std::cerr << "double: impossible" << std::endl;
    }
    else{
        if (static_cast<double>(i) == d)
            std::cout << "double: " << d << ".0" << std::endl;
        else
            std::cout << "double: " << d << std::endl;
    }
    return (0);
}