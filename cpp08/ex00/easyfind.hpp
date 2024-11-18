#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>

class FindError : public std::exception{
    public:
        const char* what() const throw(){
            return "Error: not found";
        }
};

template <typename T>
void easyfind(T container, int i){
   for (typename T::iterator it = container.begin(); it != container.end(); ++it){
      if (*it == i){
         std::cout << "find: " << *it << std::endl;
         return ;
      }
   }
   throw FindError();
}

#endif