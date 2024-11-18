#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >{
    public:
        typedef typename std::deque<T>::iterator          iterator;
        typedef typename std::deque<T>::reverse_iterator  r_iterator;
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &copy);
        MutantStack &operator=(const MutantStack &copy);

        iterator begin();
        r_iterator rbegin();

        iterator end();
        r_iterator rend();
};

#include "MutantStack.tpp"

#endif