#include "Span.hpp"
#include <ctime>

int main() 
{
    srand(time(0));

    std::cout << "SP" << std::endl;
    Span sp = Span(1);
    try{
        sp.addNumber(6); 
        sp.addNumber(3); 
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "SP1" << std::endl;
    Span sp1 = Span(1);
    try{
        sp1.addNumber(6);
        sp1.longestSpan(); 
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    Span sp2 = Span(5);
    std::cout << "SP2" << std::endl;
    try{
        sp2.addNumber(6); 
        sp2.addNumber(3); 
        sp2.addNumber(-1);
        sp2.addNumber(9); 
        sp2.addNumber(12);
        std::cout << sp2.shortestSpan() << std::endl; 
        std::cout << sp2.longestSpan() << std::endl;
    }
    catch(std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << std::endl;

    std::cout << "SP3" << std::endl;
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

    std::cout << "SP4" << std::endl;
    Span sp4 = Span(1000);
    sp4.addManyNumbers(1000);

    std::cout << sp4.shortestSpan() << std::endl; 
    std::cout << sp4.longestSpan() << std::endl;
    std::cout << std::endl;


    Span sp5(10);
    std::vector<long long> random_number(11);
    std::vector<long long>::iterator it;
    for (it = random_number.begin(); it != random_number.end(); it++){
        *it = rand() % sp5.getN();
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    try{
        sp5.addNumber(random_number.begin(), random_number.end());
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
    std::cout << sp5.shortestSpan() << std::endl; 
    std::cout << sp5.longestSpan() << std::endl;
    return 0;
}