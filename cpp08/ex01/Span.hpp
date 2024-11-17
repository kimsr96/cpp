#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>

class Span{
    private:
        unsigned int                        _N;
        std::vector<unsigned int>           vec;
    public:
        Span();
        Span(unsigned int N);
        void            addNumber(unsigned int N);
        void            addManyNumbers(unsigned int N);
        unsigned int    shortestSpan();
        unsigned int    longestSpan();
    
    class OutOfIndex : public std::exception{
        public:
            const char* what() const throw(); 
    };
    class NotEnoughElement : public std::exception{
        public:
            const char* what() const throw();
    };
};

#endif