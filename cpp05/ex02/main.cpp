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

    //Error Case
    b.executeForm(s);
    b.executeForm(p);
    b.executeForm(r);
    try{
        s.execute(a);
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }

    try{
        p.execute(a);
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }

    try{
        r.execute(a);
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }

    //Success Case
    std::cout <<  std::endl << std::endl;
    
    a.signForm(s);
    a.signForm(p);
    a.signForm(r);

    a.executeForm(s);
    a.executeForm(p);
    a.executeForm(r);

    try{
        s.execute(a);
        p.execute(a);
        for (int i = 0; i < 5; i++){
            r.execute(a);
        }
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}