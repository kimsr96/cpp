#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(std::string targetName) : AForm(targetName, false, 145, 137), target(targetName){
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy), target(copy.target){
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& copy){
    if (this != &copy){
        target = copy.target;
    }
    return *this;
} 

const std::string& ShrubberyCreationForm::getTarget(){
    return target;
}

void    ShrubberyCreationForm::execute(Bureaucrat const & executor){
    if (this->getSignStatus() && this->getExecuteGrade() >= executor.getGrade())
    {
        std::cout << "Creating file " << this->getTarget() << "_shruberry" << std::endl;
        std::ofstream outFile(this->getTarget() + "_shruberry");
        if (!outFile.is_open()){
            std::cout << "Fail to open" << std::endl;
            return ;
        }
        outFile << "                                                        ." << std::endl;
        outFile << "                                      .         ;  " << std::endl;
        outFile << "         .              .              ;%     ;;   " << std::endl;
        outFile << "           ,           ,                :;%  %;   " << std::endl;
        outFile << "            :         ;                   :;%;'     .,   " << std::endl;
        outFile << "   ,.        %;     %;            ;        %;'    ,;" << std::endl;
        outFile << "     ;       ;%;  %%;        ,     %;    ;%;    ,%'" << std::endl;
        outFile << "      %;       %;%;      ,  ;       %;  ;%;   ,%;' " << std::endl;
        outFile << "       ;%;      %;        ;%;        % ;%;  ,%;'" << std::endl;
        outFile << "        `%;.     ;%;     %;'         `;%%;.%;'" << std::endl;
        outFile << "         `:;%.    ;%%. %@;        %; ;@%;%'" << std::endl;
        outFile << "            `:%;.  :;bd%;          %;@%;'" << std::endl;
        outFile << "              `@%:.  :;%.         ;@@%;'   " << std::endl;
        outFile << "                `@%.  `;@%.      ;@@%;         " << std::endl;
        outFile << "                  `@%%. `@%%    ;@@%;        " << std::endl;
        outFile << "                    ;@%. :@%%  %@@%;       " << std::endl;
        outFile << "                      %@bd%%%bd%%:;     " << std::endl;
        outFile << "                        #@%%%%%:;;" << std::endl;
        outFile << "                        %@@%%%::;" << std::endl;
        outFile << "                        %@@@%(o);  . '         " << std::endl;
        outFile << "                        %@@@o%;:(.,'         " << std::endl;
        outFile << "                    `.. %@@@o%::;         " << std::endl;
        outFile << "                       `)@@@o%::;         " << std::endl;
        outFile << "                        %@@(o)::;        " << std::endl;
        outFile << "                       .%@@@@%::;         " << std::endl;
        outFile << "                       ;%@@@@%::;.          " << std::endl;
        outFile << "                      ;%@@@@%%:;;;. " << std::endl;
        outFile << "                  ...;%@@@@@%%:;;;;,..   " << std::endl;
    }
    else {
        throw GradeTooLowException();
    }
}