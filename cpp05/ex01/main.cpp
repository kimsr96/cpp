#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){
    Bureaucrat a("a", 1);
    Bureaucrat b("b", 2);
    Form f("form", false, 1, 1);

    a.signForm(f);
    b.signForm(f);
    
    try{
        f.beSigned(b);
    }
    catch (std::exception & e){
        std::cerr << e.what() << std::endl;
    }   

    std::cout << f << std::endl;
    return 0;
}