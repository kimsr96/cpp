#include "AForm.hpp"

AForm::AForm() : name("default"), isSigned(false), signGrade(42), executeGrade(42){
}

AForm::AForm(std::string inputName, bool sign, const int inputSignGrade, const int inputExecuteGrade)
    : name(inputName), isSigned(sign), signGrade(inputSignGrade), executeGrade(inputExecuteGrade){
    }

AForm::~AForm(){
}

AForm::AForm(const AForm &copy) : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade){
}

AForm& AForm::operator=(const AForm& copy){
    if (this != &copy){
        isSigned = copy.isSigned;
    }
    return *this;
}

const std::string& AForm::getName() const{
    return name;    
}

bool AForm::getSignStatus() const{
    return isSigned;
}

int AForm::getSignGrade() const{
    return signGrade;
}

int AForm::getExecuteGrade() const{
    return executeGrade;
}

void    AForm::setSignTrue(){
    isSigned = true;
}

void    AForm::beSigned(Bureaucrat &b){
    if (b.getGrade() <= getSignGrade())
    {
        std::cout << b.getName() << " signed " << getName() << std::endl;
        setSignTrue();
    }
    else
        throw GradeTooLowException();
}

const char* AForm::GradeTooHighException::what() const throw(){
    return "Grade Too High!!";
}

const char* AForm::GradeTooLowException::what() const throw(){
    return "Grade Too Low!!";
}

std::ostream &operator<<(std::ostream &out, const AForm &target) {
    out << "==========AForm INFO==========" << std::endl;
    out << "AForm name is " << target.getName() << std::endl;
    if (target.getSignStatus())
        out << target.getName() << "is not signed" << std::endl;
    else
        out << target.getName() << " is signed" << std::endl;
    out << "Sign Grade is " << target.getSignGrade() << std::endl;
    out << "Execute Grade is " << target.getExecuteGrade() << std::endl;
    out << "=============================";
    return out;
}