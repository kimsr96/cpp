#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"
#include "Intern.hpp"

int main(void){
    Intern seungryk;
    AForm* rrf;

    rrf = seungryk.makeForm("robotomy", "Bender");
    rrf = seungryk.makeForm("shrubbery", "Bender");
    rrf = seungryk.makeForm("presidential", "Bender");

    //Error case
    try{
        rrf = seungryk.makeForm("abc", "Bender");
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    return 0;
}