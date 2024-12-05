#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _size(0), _cmp(0) {}

PmergeMe::~PmergeMe() {}

void PmergeMe::printVector() {
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it){
        if (*it != -1)
            std::cout << *it << " "; 
    }
    std::cout << std::endl;
}

void PmergeMe::printList() {
    for (std::list<int>::iterator it = _list.begin(); it != _list.end();){
        //if (*it != -1)
            std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

void    PmergeMe::pushElement(int argc, char **argv){
    for (int i = 1; i < argc; i++){
        _vec.push_back(std::atoi(argv[i]));
        _list.push_back(std::atoi(argv[i]));
    }
    _size = argc - 1;
    if (argc % 2 == 0){
        _vec.push_back(-1);
        _list.push_back(-1);
        _size += 1;
    }
}

void    PmergeMe::mergeInsert(int argc, size_t cnt){
    if (cnt * 2 > static_cast<size_t>(argc - 1)){
        return ;
    }
    else{
        for (std::vector<int>::iterator it = _vec.begin(); it < _vec.end() - cnt; it += cnt * 2){
            std::vector<int>::iterator it2 = it + cnt;
            _cmp++;
            if (*it2 > *it){
                for (size_t i = 0; i < cnt && (it2 + i) < _vec.end(); i++){
                    std::swap(*(it + i), *(it2 + i));
                }
            }
        }
        mergeInsert(argc, cnt * 2);
        insert(cnt);
    }
}

void    PmergeMe::mergeInsertList(int argc, size_t cnt){
    if (cnt >= static_cast<size_t>(argc - 1)){
        return ;
    }
    else{
        size_t idx = 0;
        for (std::list<int>::iterator it = _list.begin(); it != _list.end();){
            std::list<int>::iterator nextIt = it;
            if (idx + cnt >= _list.size())
                break;
            std::advance(nextIt, cnt);
            if (nextIt == _list.end() || (_list.size() / cnt) < 2)
                break;
            std::cout << "it: " << *it << " nextIt " << *nextIt << std::endl;
            if (*nextIt > *it){
                std::list<int>::iterator tmp_it = it;
                std::list<int>::iterator tmp_nextIt = nextIt;
                for (size_t i = 0; i < cnt && i + idx < _list.size(); i++){
                    std::swap(*tmp_it, *tmp_nextIt);
                    ++tmp_it;
                    ++tmp_nextIt;
                }
            }
            idx += (cnt * 2);
            std::advance(it, cnt * 2);
        }
        std::cout << "cnt: " << cnt << std::endl;
        mergeInsertList(argc, cnt * 2);
        insertList(cnt);
        //printList();
        std::cout << std::endl;
    }
}

void    PmergeMe::insertList(size_t cnt){
    int                 pos = 0;
    size_t              idx = 0;;
    std::list<int>      a;
    std::list<int>      b;

    printList();

    for (std::list<int>::iterator it = _list.begin(); it != _list.end();){
        std::list<int>::iterator itEnd = it;
        size_t remaining = std::distance(it, _list.end());
        if (remaining < cnt)
            itEnd = _list.end();
        else
            std::advance(itEnd, cnt);
        if (itEnd == _list.end())
            break ;
        pos++;
        idx += cnt;
        std::advance(it, cnt);
    }
    std::cout << "a: ";
    for (std::list<int>::iterator it = a.begin(); it != a.end();){
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl << "b: ";
    for (std::list<int>::iterator it = b.begin(); it != b.end();){
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
}

int PmergeMe::Jacobsthal(int n){
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

int PmergeMe::binarySearch(std::vector<int> &arr, int find, int target, int cnt){
    int left = 0;
    int right = 0;

    std::vector<int>::iterator it = std::find(arr.begin(), arr.end(), find);
    if (it != arr.end())
        right = std::distance(arr.begin(), it);
    while (left <= right){
        int mid = left + (right - left) / 2;
        if (mid % 2 != 0 && mid > left)
            mid -= 1;
        if (arr[mid] < target)
            left = mid + cnt;
        else
            right = mid - cnt;
    }
    return left;
}

void    PmergeMe::generateJacobsthal(std::vector<size_t> & jacob, size_t limit){
    int     idx = 2;
    size_t  lastValue = 0;
    while (true){
        size_t value = Jacobsthal(idx);
        if (value >= limit)
            value = limit;
        for (size_t i = value; i > lastValue; i--)
            jacob.push_back(i);
        if (value == limit)
            break;
        lastValue = value;
        idx++;
    }
}

void    PmergeMe::insert(size_t cnt){
    int                 idx = 0;
    std::vector<int>    a;
    std::vector<int>    b;
    std::vector<int>    tmp;
    std::vector<size_t> _Jacob;

    
    for (std::vector<int>::iterator it = _vec.begin(); it < _vec.end(); it += cnt){
        std::vector<int>::iterator itEnd = (it + cnt > _vec.end()) ? _vec.end() : it + cnt;
        if (it + cnt > _vec.end())
            a.insert(a.end(), it, itEnd);
        else if ((_size / cnt) % 2 == 1 && idx == static_cast<int>(_size / cnt) - 1)
            b.insert(b.end(), it, itEnd);
        else
            (idx % 2 == 0 ? a : b).insert((idx % 2 == 0 ? a : b).end(), it, itEnd);
        idx++;
    }

    generateJacobsthal(_Jacob, b.size() / cnt);

    _vec.clear();
    _vec = a;
    std::vector<size_t>::iterator itJab = _Jacob.begin();
    std::vector<int>::iterator  itb = b.begin();
    for (size_t i = 0; i < b.size(); i += cnt){
        std::vector<int>::iterator  targetB = itb + cnt * (*itJab - 1);
        std::vector<int>::iterator  itbEnd = (targetB + cnt > b.end()) ? b.end() : targetB + cnt;
        size_t idx = cnt * (*itJab - 1) >= a.size() ? a.size() - 1 : cnt * (*itJab - 1);
        int pos = binarySearch(_vec, a[idx], *targetB, cnt);
        std::vector<int>::iterator  _vecEnd = (_vec.begin() + pos > _vec.end()) ? _vec.end() : _vec.begin() + pos;
        _vec.insert(_vecEnd, targetB, itbEnd);
        itJab++;
    }
    a.clear();
    b.clear();
}
