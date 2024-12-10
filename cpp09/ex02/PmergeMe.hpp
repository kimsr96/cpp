#ifndef PMERGEME_HPP
# define PMERGEME_HPP

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>


class PmergeMe{
    private:
        std::vector<int>    _vec;
        std::list<int>      _list;
        size_t              _size;
        int                 *_jacob;
 
    public:
        PmergeMe();
        PmergeMe(int argc);
        ~PmergeMe();

        int     Jacobsthal(int n);

        void    generateJacobsthal(size_t n);
        //int     binarySearch(std::vector<int> &arr, size_t find, int target, int cnt);
        //std::list<int>::iterator  binarySearch(std::list<int> &arr, int find, int target);
        int     binarySearch(std::list<int> &arr, int find, int target);
        
        void    printVector();
        void    printList();
        
        void    pushElement(int argc, char **argv);
        void    insert(size_t cnt);
        void    insertList(size_t cnt);
        void    mergeInsert(int argc, size_t cnt);
        void    mergeInsertList(int argc, size_t cnt);
        
};
#endif