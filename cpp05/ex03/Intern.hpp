#ifndef INTERN_HPP
# define INTERN_HPP

#include "AForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"

class Intern{
    public:
        Intern();
        ~Intern();
        Intern(const Intern &copy);
        Intern &operator=(const Intern &copy);

        AForm* makeForm(const std::string& name, const std::string& target);
        class FormNameException : public std::exception{
            public:
                const char* what() const throw();
        };
};

#endif