#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm{
    private:
        std::string target;
    public:
        PresidentialPardonForm(std::string targetName);
        ~PresidentialPardonForm();
        PresidentialPardonForm(const PresidentialPardonForm &copy);
        PresidentialPardonForm &operator=(const PresidentialPardonForm &copy);

        const std::string&      getTarget() const;
        void                    execute(Bureaucrat const & executor) const;
};

#endif