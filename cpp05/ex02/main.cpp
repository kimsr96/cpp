#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"

int main(void){
    std::srand(std::time(0));

    Bureaucrat a("a", 1);
    Bureaucrat b("b", 150);
    ShrubberyCreationForm   s("s_form");
    PresidentialPardonForm  p("p_form");
    RobotomyRequestForm     r("r_form");

    a.signForm(s);
    a.signForm(p);
    a.signForm(r);
    //Error Case

    //Try to unsigned form
    try{
        b.executeForm(s);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        b.executeForm(p);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        b.executeForm(r);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    //Success Case
    std::cout <<  std::endl;
    
    try{
        a.executeForm(s);
        a.executeForm(p);
        for (int i = 0; i < 5; i++){
            a.executeForm(r);
        }
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}