#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

template <typename T>
class EasyFind{
    private:
        EasyFind();
        ~EasyFind();
        EasyFind(const EasyFind &copy);
        EasyFind &operator=(const EasyFind &copy);
    public:
        static void easyfind(T container, int i);
    class FindError : public std::exception{
        public:
            const char* what() const throw();
    };
};

#include "easyfind.tpp"

#endif