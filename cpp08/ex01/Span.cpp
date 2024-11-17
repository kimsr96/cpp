#include "Span.hpp"

Span::Span() : _N(0){
}

Span::Span(unsigned int N) : _N(N){
}

void Span::addNumber(unsigned int num){
    if (vec.size() >= _N)
        throw OutOfIndex();
    vec.push_back(num);
}

void    Span::addManyNumbers(unsigned int num){
    if (vec.size() + num > _N)
        throw OutOfIndex();
    for (unsigned int i = 0; i < num; i++){
        vec.push_back(rand() % num);
    }
}

unsigned int    Span::shortestSpan(){
    if (vec.size() > 1 ){
        unsigned int min_span = UINT_MAX;
        unsigned int span;
        for (std::vector<unsigned int>::iterator it = vec.begin(); it != vec.end() - 1; ++it){
            for (std::vector<unsigned int>::iterator it2  = it + 1; it2 != vec.end(); ++it2){
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

unsigned int    Span::longestSpan(){
    if (vec.size() > 1){
        std::vector<unsigned int>   sorted_vec = vec;
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