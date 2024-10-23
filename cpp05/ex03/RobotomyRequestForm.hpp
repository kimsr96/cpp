#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <cstdlib>
#include <ctime>

class RobotomyRequestForm : public AForm{
    private:
        std::string target;
    public:
        RobotomyRequestForm(std::string targetName);
        ~RobotomyRequestForm();
        RobotomyRequestForm(const RobotomyRequestForm &copy);
        RobotomyRequestForm &operator=(const RobotomyRequestForm &copy);

        const std::string&      getTarget() const;
        void                    execute(Bureaucrat const & executor) const;
};

#endif