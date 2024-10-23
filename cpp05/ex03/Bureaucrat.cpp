#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(42){
}

Bureaucrat::Bureaucrat(std::string input_name, int input_grade) : name(input_name), grade(input_grade){
    if (input_grade < 1)
        throw GradeTooHighException();
    else if (input_grade > 150)
        throw GradeTooLowException();
}

Bureaucrat::~Bureaucrat(){
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) : name(copy.name), grade(copy.grade){
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& copy){
    if (this != &copy){
        grade = copy.getGrade();
        name = copy.getName();
    }
    return *this;
}

const std::string& Bureaucrat::getName() const{
    return name;
}

int Bureaucrat::getGrade() const{
    return grade;
}

void    Bureaucrat::incrementGrade(){
    grade--;
    if (grade < 1){
        grade++;
        throw GradeTooHighException();
    }
}

void    Bureaucrat::decrementGrade(){
    grade++;
    if (grade > 150){
        grade--;
        throw GradeTooLowException();
    }
}

void    Bureaucrat::signForm(AForm & form){
    try{
        form.beSigned(*this);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm(AForm const & form){
    try{
        form.execute(*this);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }       
}

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade Too High!!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade Too Low!!";
}

const char* Bureaucrat::SignException::what() const throw(){
    return "Sign not possible";
}

const char* Bureaucrat::ExecuteException::what() const throw(){
    return "Execute not possible";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &target) {
    out << target.getName() << ", bureaucrat grade " << target.getGrade() << ".";
    return out;
}