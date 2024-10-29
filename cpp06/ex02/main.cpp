#include "Base.hpp"

int main(void){

    Base *a = generate();
    identify(a);
    identify(*a);

    delete a;
    return (0);
}
