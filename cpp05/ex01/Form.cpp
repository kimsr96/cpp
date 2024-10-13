#include "Form.hpp"

Form::Form() : name("default"), isSigned(false), signGrade(42), executeGrade(42){
}

Form::Form(std::string inputName, bool sign, const int inputSignGrade, const int inputExecuteGrade)
    : name(inputName), isSigned(sign), signGrade(inputSignGrade), executeGrade(inputExecuteGrade){
    }

Form::~Form(){
}

Form::Form(const Form &copy) : name(copy.name), isSigned(copy.isSigned), signGrade(copy.signGrade), executeGrade(copy.executeGrade){
}

Form& Form::operator=(const Form& copy){
    if (this != &copy){
        //name = copy.getName();
        isSigned = copy.isSigned;
        //signGrade = copy.signGrade;
        //executeGrade = copy.executeGrade;
    }
    return *this;
}

const std::string& Form::getName() const{
    return name;    
}

bool Form::getSignStatus() const{
    return isSigned;
}

int Form::getSignGrade() const{
    return signGrade;
}

int Form::getExecuteGrade() const{
    return executeGrade;
}

void    Form::changeSignStatus(){
    if (isSigned)
        isSigned = false;
    else
        isSigned = true;
}

void    Form::beSigned(Bureaucrat &b){
    if (b.getGrade() <= getSignGrade())
    {
        std::cout << b.getName() << " signed " << getName() << std::endl;
        changeSignStatus();
    }
    else
        throw GradeTooLowException();
}

const char* Form::GradeTooHighException::what() const throw(){
    return "Grade Too High!!";
}

const char* Form::GradeTooLowException::what() const throw(){
    return "Grade Too Low!!";
}

std::ostream &operator<<(std::ostream &out, const Form &target) {
    out << "==========FORM INFO==========" << std::endl;
    out << "Form name is " << target.getName() << std::endl;
    if (target.getSignStatus())
        out << target.getName() << "is not signed" << std::endl;
    else
        out << target.getName() << " is signed" << std::endl;
    out << "Sign Grade is " << target.getSignGrade() << std::endl;
    out << "Execute Grade is " << target.getExecuteGrade() << std::endl;
    out << "=============================";
    return out;
}