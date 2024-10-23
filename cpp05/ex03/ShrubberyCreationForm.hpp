#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm{
    private:
        std::string target;
    public:
        ShrubberyCreationForm(std::string targetName);
        ~ShrubberyCreationForm();
        ShrubberyCreationForm(const ShrubberyCreationForm &copy);
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm &copy);

        const std::string&      getTarget() const;
        void                    execute(Bureaucrat const & executor) const;
};

#endif