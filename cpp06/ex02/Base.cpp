#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"


Base::~Base(){
}

Base * generate(void){
    int i = std::rand() % 3;
    if (i == 0)
        return new A();
    else if (i == 1)
        return new B();
    else
        return new C();
}

void    identify(Base* p){
    if (dynamic_cast<A*>(p))
        std::cout << "Base is A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "Base is B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "Base is C" << std::endl;
    else
    {
        std::cout << "Base is not matched" << std::endl;
        return ;
    }
}

void    identify(Base& p){
    try{
        A& aRef = dynamic_cast<A&>(p);
        (void)aRef;
        std::cout << "Base is A" << std::endl;
    } catch (const std::exception & e){
        try{
            B& bRef = dynamic_cast<B&>(p);
            (void)bRef;
            std::cout << "Base is B" << std::endl;
        } catch (const std::exception & e){
            try{
                C& cRef = dynamic_cast<C&>(p);
                (void)cRef;
                std::cout << "Base is C" << std::endl;
            }catch (const std::exception & e){
                std::cout << "Base is not matched" << std::endl;
            }
        }
    }
}