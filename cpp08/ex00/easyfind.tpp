#include "easyfind.hpp"

template <typename T>
const char* EasyFind<T>::FindError::what() const throw(){
   return "Error: not found";
}

template <typename T>
void EasyFind<T>::easyfind(T container, int i){
   for (typename T::iterator it = container.begin(); it != container.end(); ++it){
      if (*it == i){
         std::cout << "find: " << *it << std::endl;
         return ;
      }
   }
   throw FindError();
}