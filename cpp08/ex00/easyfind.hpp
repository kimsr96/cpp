#ifndef EASYFIND_HPP
# define EASYFIND_HPP

#include <iostream>
#include <algorithm>

class FindError : public std::exception{
    public:
        const char* what() const throw(){
            return "Error: not found";
        }
};

template <typename T>
void easyfind(T container, int i){
   typename T::iterator it;

   it = find(container.begin(), container.end(), i);
   if (it == container.end())
      throw FindError();
   else
      std::cout << "Find:" << *it << std::endl;
}

#endif