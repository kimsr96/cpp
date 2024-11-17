#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

#include <iostream>
#include <stack>
#include <deque>

template <typename T>
class MutantStack : public std::stack<T, std::deque<T> >{
    public:
        typedef typename std::deque<T>::iterator        iterator;
        typedef typename std::deque<T>::const_iterator  const_iterator;
        MutantStack();
        ~MutantStack();
        MutantStack(const MutantStack &copy);
        MutantStack &operator = (const MutantStack &copy);

        iterator begin();
        const_iterator cbegin();
        iterator rbegin();
        const_iterator crbegin();

        iterator end();
        const_iterator cend();
        iterator rend();
        const_iterator crend();

};

#include "MutantStack.tpp"

#endif