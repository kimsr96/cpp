#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <vector>
#include <cstdlib>
#include <climits>

class Span{
    private:
        unsigned int            _N;
        std::vector<long long>  vec;
    public:
        Span();
        Span(unsigned int N);
        ~Span();
        Span(const Span &copy);
        Span &operator=(const Span &copy);

        unsigned int    getN();
        void            addNumber(long long num);
        void            addNumber(std::vector<long long>::iterator begin, std::vector<long long>::iterator end);
        void            addManyNumbers(long long num);
        long long       shortestSpan();
        long long       longestSpan();

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