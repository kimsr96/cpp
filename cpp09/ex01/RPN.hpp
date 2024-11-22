#ifndef RPN_HPP
# define RPN_HPP

#include <stack>
#include <iostream>

class RPN{
    private:
        std::stack<int>    _stack;
    public:
        void    splitData(char *argv);
        void    calculateStack(char oper);
        void    result();
        class NotEnoughElement : public std::exception{
        public:
            const char* what() const throw();
        };
        class DivideZeroException : public std::exception{
        public:
            const char* what() const throw();
        };
        class ErrorException : public std::exception{
        public:
            const char* what() const throw();
        };
};


#endif