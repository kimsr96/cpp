#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>

class Span{
    private:
        unsigned int                        _N;
        std::vector<unsigned int>           vec;
    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span &copy);
        Span &operator=(const Span &copy);

        unsigned int    getN();
        void            addNumber(unsigned int N);
        void            addNumber(std::vector<unsigned int>::iterator begin, std::vector<unsigned int>::iterator end);
        void            addManyNumbers(unsigned int num);
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