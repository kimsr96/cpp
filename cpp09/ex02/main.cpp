#include "PmergeMe.hpp"
#include <climits>
#include <ctime>
#include <iomanip>

int main(int argc, char **argv){

    if (argc < 3){
        std::cerr << "Error: not enough element" << std::endl;
        return 1;
    }
    for (int i = 1; i < argc; i++){
        long    num;
        char*   endptr;
        num = std::strtol(argv[i], &endptr, 10);
        if (*endptr != '\0' || num < 0 || num > INT_MAX){
            std::cerr << "Error" << std::endl;
            return 1;
        }
    }
    PmergeMe _stl;

    _stl.pushElement(argc, argv);

    PmergeMe vec = _stl;
    PmergeMe list = _stl;

    std::cout << "Before: ";
    vec.printVector();

    //clock_t start = clock();
    vec.mergeInsert(argc, 1);
    //clock_t end = clock();

    //double timer = double(end - start) / CLOCKS_PER_SEC;
    
    std::cout << "After: ";
    vec.printVector();

    //list.mergeInsertList(argc, 1);
    //list.printList();
    //std::cout << std::fixed << std::setprecision(5);
    //std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << timer << " us" << std::endl;    
    return 0;
}