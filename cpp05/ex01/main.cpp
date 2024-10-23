#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void){
    Bureaucrat a("a", 1);
    Bureaucrat b("b", 2);
    Form f("form", 1, 1);

    a.signForm(f);
    b.signForm(f); //b's grade is lower than form's grade 

    std::cout << f << std::endl;
    return 0;
}