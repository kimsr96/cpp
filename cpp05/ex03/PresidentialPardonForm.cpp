#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string targetName) : AForm(targetName, false, 25, 5), target(targetName){
}

PresidentialPardonForm::~PresidentialPardonForm(){
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy), target(copy.target){
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& copy){
    if (this != &copy){
        target = copy.target;
    }
    return *this;
} 

const std::string& PresidentialPardonForm::getTarget(){
    return target;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor){
    if (this->getSignStatus() && this->getExecuteGrade() >= executor.getGrade()){
        std::cout << this->getTarget() << " pardoned by Zaphod Beeblebrox" << std::endl;
    }
    else {
        throw GradeTooLowException();
    }
}