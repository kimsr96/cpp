#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string targetName) : AForm(targetName, 25, 5), target(targetName){
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

const std::string& PresidentialPardonForm::getTarget() const {
    return target;
}

void    PresidentialPardonForm::execute(Bureaucrat const & executor) const{
    if (this->getSignStatus() && this->getExecuteGrade() >= executor.getGrade()){
        std::cout << this->getTarget() << " pardoned by Zaphod Beeblebrox" << std::endl;
    }
    else if (this->getSignStatus() == false)
        throw SignException();
    else
        throw GradeTooLowException();
}