#include "MutantStack.hpp"
#include <list>

int main()
{
    MutantStack<int>    mstack;
    std::list<int>      myList;
    
    mstack.push(5); 
    mstack.push(17);

    myList.push_back(5);
    myList.push_back(17);
    
    std::cout << "\033[31m" << mstack.top() << std::endl; 
    std::cout << "\033[32m" << myList.back() << std::endl;
    std::cout << std::endl;

    mstack.pop();
    myList.pop_back();
    
    std::cout << "\033[31m" << mstack.size() << std::endl;
    std::cout << "\033[32m" << myList.size() << std::endl;
    std::cout << std::endl;

    mstack.push(3); 
    mstack.push(5); 
    mstack.push(737); 
    mstack.push(0);

    myList.push_back(3); 
    myList.push_back(5); 
    myList.push_back(737); 
    myList.push_back(0);

    MutantStack<int>::iterator it = mstack.begin(); 
    MutantStack<int>::iterator ite = mstack.end();
    
    ++it;
    --it;
    while (it != ite) {
        std::cout << "\033[31m" << *it << std::endl;
        ++it; 
    }
    
    std::cout << std::endl;

    for (std::list<int>::iterator itl = myList.begin(); itl != myList.end(); ++itl){
        std::cout << "\033[32m" << *itl << std::endl;
    }

    std::stack<int> s(mstack);
    return 0;
}