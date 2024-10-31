#include "Base.hpp"

int main(void){
    std::srand(static_cast<unsigned int>(std::time(0)));

    Base *a = generate();
    identify(a);
    identify(*a);

    Base *b = generate();
    identify(b);
    identify(*b);

    delete a;
    delete b;
    return (0);
}
