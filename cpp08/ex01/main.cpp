#include "Span.hpp"

int main() 
{
    srand(time(0));

    Span sp = Span(1);
    try{
        sp.addNumber(6); 
        sp.addNumber(3); 
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    
    Span sp1 = Span(1);
    try{
        sp1.addNumber(6);
        sp1.longestSpan(); 
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    Span sp2 = Span(5);
    try{
        sp.addNumber(6); 
        sp.addNumber(3); 
        sp.addNumber(-1); 
        sp.addNumber(9); 
        sp.addNumber(11);
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    Span sp3 = Span(5);
    try{
        sp3.addNumber(6); 
        sp3.addNumber(3); 
        sp3.addNumber(5); 
        sp3.addNumber(9); 
        sp3.addNumber(11);
        std::cout << sp3.shortestSpan() << std::endl; 
        std::cout << sp3.longestSpan() << std::endl;
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    Span sp4 = Span(1000);
    sp4.addManyNumbers(1000);

    std::cout << sp4.shortestSpan() << std::endl; 
    std::cout << sp4.longestSpan() << std::endl;
    
    return 0; 
}