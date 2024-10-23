#include "Intern.hpp"

Intern::Intern(){
}

Intern::~Intern(){
}

Intern::Intern(const Intern &copy){
    (void)copy;
}

Intern& Intern::operator=(const Intern& copy){
    if (this != &copy){
        return *this;
    }
    return *this;
}

AForm* robotomy(const std::string& target){
    return new RobotomyRequestForm(target);    
}

AForm* shrubbery(const std::string& target){
    return new ShrubberyCreationForm(target);
}

AForm* presidential(const std::string& target){
    return new PresidentialPardonForm(target);
}

AForm* Intern::makeForm(const std::string& name, const std::string& target){
    AForm*          (*formFunc[3])(const std::string& target) = {robotomy, shrubbery, presidential};
    std::string     formList[3] = {"robotomy", "shrubbery", "presidential"};

    if (name.empty() || target.empty())
    {
        std::cerr << "ERROR" << std::endl;
        return NULL;
    }
    for (int i = 0; i < 3; i++){
        if (name == formList[i])
        {
            std::cout << "Intern creates " << name << "." << std::endl;
            return formFunc[i](target);
        }
    }
    throw FormNameException();
    return NULL;
}

const char* Intern::FormNameException::what() const throw(){
    return "FormName Error";
}