#ifndef AFORM_HPP
# define AFORM_HPP

#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm{
    private:
        const std::string   name;
        bool                isSigned;
        const int           signGrade;
        const int           executeGrade;
    public:
        AForm();
        AForm(std::string inputName, bool sign, const int inputSignGrade, const int inputExecuteGrade);
        virtual ~AForm();
        AForm(const AForm &copy);
        AForm &operator=(const AForm &copy);
        
        const std::string&          getName() const;
        bool                        getSignStatus() const;
        int                         getSignGrade() const;
        int                         getExecuteGrade() const;
        void                        beSigned(Bureaucrat &b);
        void                        setSignTrue();
        virtual void                execute(Bureaucrat const & executor) = 0;

    class GradeTooHighException : public std::exception{
        public:
            const char* what() const throw();
    };
    class GradeTooLowException : public std::exception{
        public:
            const char* what() const throw();
    };
};

std::ostream &operator<<(std::ostream &out, const AForm &target);

#endif
