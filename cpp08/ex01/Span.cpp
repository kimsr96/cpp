#include "Span.hpp"

Span::Span() : _N(0) {}

Span::Span(unsigned int N) : _N(N) {}

Span::~Span() {}

Span::Span(const Span &copy) : _N(copy._N), vec(copy.vec) {}

Span& Span::operator=(const Span &copy){
    if (this != &copy){
        _N = copy._N;
        vec = copy.vec;
    }
    return *this;
} 

unsigned int Span::getN(){
    return _N;
}

void Span::addNumber(long long num){
    if (vec.size() >= _N)
        throw OutOfIndex();
    vec.push_back(num);
}

void Span::addNumber(std::vector<long long>::iterator begin, std::vector<long long>::iterator end){
    while (begin != end){
        addNumber(*begin);
        begin++;
    }
}

void    Span::addManyNumbers(long long num){
    if (vec.size() + num > _N)
        throw OutOfIndex();
    for (unsigned int i = 0; i < num; i++){
        vec.push_back(rand() % _N);
    }
}

long long   Span::shortestSpan(){
    if (vec.size() > 1 ){
        unsigned int min_span = UINT_MAX;
        unsigned int span;
        for (std::vector<long long>::iterator it = vec.begin(); it != vec.end() - 1; ++it){
            for (std::vector<long long>::iterator it2  = it + 1; it2 != vec.end(); ++it2){
                span = (*it2 > *it) ? *it2 - *it : *it - *it2;
                if (span < min_span)
                    min_span = span;
            }
        }
        std::cout << "Shortest Span: ";
        return min_span;
    }
    else
        throw NotEnoughElement();
}

long long   Span::longestSpan(){
    if (vec.size() > 1){
        std::vector<long long>   sorted_vec = vec;
        std::sort(sorted_vec.begin(), sorted_vec.end());
        std::cout << "Longest Span: ";
        return sorted_vec.back() - sorted_vec.front();
    }
    else
        throw NotEnoughElement();
}

const char* Span::OutOfIndex::what() const throw(){
    return "Out of index";
}

const char* Span::NotEnoughElement::what() const throw(){
    return "Not enough Element";
}