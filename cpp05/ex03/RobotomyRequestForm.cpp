#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(std::string targetName) : AForm(targetName, 72, 45), target(targetName){
}

RobotomyRequestForm::~RobotomyRequestForm(){
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy), target(copy.target){
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& copy){
    if (this != &copy){
        target = copy.target;
    }
    return *this;
} 

const std::string& RobotomyRequestForm::getTarget() const{
    return target;
}


void    RobotomyRequestForm::execute(Bureaucrat const & executor) const{
    if (this->getSignStatus() && this->getExecuteGrade() >= executor.getGrade())
    {
        if (std::rand() % 2 == 0)
            std::cout << "Drrrr..." << std::endl;
        else
            std::cout << "Robotomy failed" << std::endl;
    }
    else if (this->getSignStatus() == false)
        throw SignException();
    else
        throw GradeTooLowException();
}