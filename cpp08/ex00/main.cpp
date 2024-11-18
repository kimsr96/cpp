#include "easyfind.hpp"
#include <vector>
#include <list>

int main(void){
    std::vector<int>    i_vec;
    std::list<int>      i_list;

    for (int i = 0; i < 10; i++){
        i_vec.push_back(i);
        i_list.push_back(i);
    }

    try{
        easyfind(i_vec, 1);
        easyfind(i_vec, 11);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }

    try{
        easyfind(i_vec, 2);
        easyfind(i_vec, 22);
    }
    catch (std::exception &e){
        std::cerr << e.what() << std::endl;
    }
}