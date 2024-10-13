#include "Bureaucrat.hpp"

int main(void){
    Bureaucrat a("a", 1);
    Bureaucrat b("b", 150);
    Bureaucrat c;
    
    try{
        a.incrementGrade();
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }

    try{
        b.decrementGrade();
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }

    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
}