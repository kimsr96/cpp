#ifndef FORM_CPP
# define FORM_CPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form{
    private:
        const std::string   name;
        bool                isSigned;
        const int           signGrade;
        const int           executeGrade;
    public:
        Form();
        Form(std::string inputName, const int inputSignGrade, const int inputExecuteGrade);
        ~Form();
        Form(const Form &copy);
        Form &operator=(const Form &copy);
        
        const std::string&  getName() const;
        bool                getSignStatus() const;
        int                 getSignGrade() const;
        int                 getExecuteGrade() const;
        void                beSigned(Bureaucrat &b);
        void                setSignTrue();

    class GradeTooHighException : public std::exception{
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const Form &target);

#endif
