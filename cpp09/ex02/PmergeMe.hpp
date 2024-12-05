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
        int                 _cmp;
 
    public:
        PmergeMe();
        ~PmergeMe();

        void    printVector();
        void    printList();
        
        void    pushElement(int argc, char **argv);
        int     Jacobsthal(int n);
        void    generateJacobsthal(std::vector<size_t> & jacob, size_t n);
        void    insert(size_t cnt);
        void    insertList(size_t cnt);
        void    mergeInsert(int argc, size_t cnt);
        void    mergeInsertList(int argc, size_t cnt);
        int     binarySearch(std::vector<int> &arr, int find, int target, int cnt);
};
#endif