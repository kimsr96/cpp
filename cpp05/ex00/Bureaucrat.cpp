#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : name("default"), grade(42){
}

Bureaucrat::Bureaucrat(std::string input_name, int input_grade) : name(input_name), grade(input_grade){
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

const char* Bureaucrat::GradeTooHighException::what() const throw(){
    return "Grade Too High!!";
}

const char* Bureaucrat::GradeTooLowException::what() const throw(){
    return "Grade Too Low!!";
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &target) {
    out << target.getName() << ", bureaucrat grade " << target.getGrade() << ".";
    return out;
}