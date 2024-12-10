#include "PmergeMe.hpp"

PmergeMe::PmergeMe() : _size(0){}

PmergeMe::PmergeMe(int argc){
    if (argc % 2 == 0)
        _size = argc;
    else
        _size = argc - 1;
    _jacob = new int[_size];
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printVector(){
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it){
        if (*it != -1)
            std::cout << *it << " "; 
    }
    std::cout << std::endl;
}

void PmergeMe::printList() {
    for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it){
        if (*it != -1)
            std::cout << *it << " ";
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

int PmergeMe::Jacobsthal(int n){
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else
        return Jacobsthal(n - 1) + 2 * Jacobsthal(n - 2);
}

void    PmergeMe::generateJacobsthal(size_t limit){
    int     idx = 2;
    int     j = 0;
    size_t  lastValue = 0;
    while (true){
        size_t value = Jacobsthal(idx);
        if (value >= limit)
            value = limit;
        for (size_t i = value; i > lastValue; i--){
            _jacob[j] = i;
            j++;
        }
        if (value == limit)
            break;
        lastValue = value;
        idx++;
    }
}

void    PmergeMe::mergeInsert(int argc, size_t cnt){
    if (cnt * 2 > _size)
        return ;
    else{
        for (std::vector<int>::iterator it = _vec.begin(); it + cnt < _vec.end(); it += cnt * 2){
            std::vector<int>::iterator it2 = it + cnt;
            if (it2 + cnt > _vec.end())
                break ;
            if (*it2 > *it){
                for (size_t i = 0; i < cnt; i++)
                    std::swap(*(it + i), *(it2 + i));
            }
        }
        mergeInsert(argc, cnt * 2);
        insert(cnt);
    }
}

void    PmergeMe::insert(size_t cnt){
    std::vector<int>    a, b;
    
    int i = 0;
    for (std::vector<int>::iterator it = _vec.begin(); it < _vec.end(); it += cnt){
        std::vector<int>::iterator itEnd = (it + cnt > _vec.end()) ? _vec.end() : it + cnt;
        if (it + cnt > _vec.end())
            a.insert(a.end(), it, itEnd);
        else if ((_size / cnt) % 2 == 1 && i == static_cast<int>(_size / cnt) - 1)
            b.insert(b.end(), it, itEnd);
        else
            (i % 2 == 0 ? a : b).insert((i % 2 == 0 ? a : b).end(), it, itEnd);
        i++;
    }
    generateJacobsthal(b.size() / cnt);
    _vec.clear();
    _vec = a;
    int j = 0;
    std::vector<int> newArr;
    for (size_t i = 0; i < b.size(); i += cnt){
        std::vector<int>::iterator  targetB = b.begin() + cnt * (_jacob[j] - 1);
        std::vector<int>::iterator  itbEnd = (targetB + cnt > b.end()) ? b.end() : targetB + cnt;
        std::vector<int>::iterator  arrEnd;
        for (size_t i = 0; i + cnt <= _vec.size(); i += cnt)
            newArr.push_back(_vec[i]);
        if (_jacob[j] >= static_cast<int>(a.size() / cnt))
            arrEnd = newArr.end();
        else
            arrEnd = newArr.begin() + (_jacob[j] - 1) + (i / cnt); //newArr + b element
        if (*targetB != -1){
            std::vector<int>::iterator pos = std::lower_bound(newArr.begin(), arrEnd, *targetB);
            size_t distance = std::distance(newArr.begin(), pos);
            _vec.insert(_vec.begin() + distance * cnt, targetB, itbEnd);
        }
        newArr.clear();
        j++;
    }
    a.clear();
    b.clear();
}

void    PmergeMe::mergeInsertList(int argc, size_t cnt){
    if (cnt * 2 > _size)
        return ;
    else{
        size_t idx = 0;
        size_t size = _list.size();
        for (std::list<int>::iterator it = _list.begin(); it != _list.end();){
            std::list<int>::iterator nextIt = it;
            if (idx + cnt > size)
                break;
            std::advance(nextIt, cnt);
            if (nextIt != _list.end() && *nextIt > *it){
                if (idx + 2 * cnt > _list.size())
                    break ;
                std::list<int>::iterator tmp_it = it;
                std::list<int>::iterator tmp_nextIt = nextIt;
                for (size_t i = 0; i < cnt && i + idx < size; i++){
                    std::swap(*tmp_it, *tmp_nextIt);
                    ++tmp_it;
                    ++tmp_nextIt;
                }
            }
            idx += (cnt * 2);
            if (idx > size)
                break ; 
            std::advance(it, cnt * 2);
        }
        mergeInsertList(argc, cnt * 2);
        insertList(cnt);
    }
}

int PmergeMe::binarySearch(std::list<int> &arr, int right, int target){
    int left = 0;
    std::list<int>::iterator begin;
    
    while (left <= right){
        begin = arr.begin();
        int mid = left + (right - left) / 2;
        std::advance(begin, mid);
        if (*begin < target){
            left = mid + 1;
            begin++;
        }
        else
            right = mid - 1;
    }
    while (*begin < target && begin != arr.end()){
        begin++;
        left++;
    }
    return left;
}

void    PmergeMe::insertList(size_t cnt){
    std::list<int>      a, b;
    size_t              i = 0;;

    for (std::list<int>::iterator it = _list.begin(); it != _list.end();){
        std::list<int>::iterator itEnd = it;
        if (cnt + i * cnt > _list.size()){
            a.insert(a.end(), it, _list.end());
            break ;
        }
        std::advance(itEnd, cnt);
        if ((_size / cnt) % 2 == 1 && i == (_size / cnt) - 1)
            b.insert(b.end(), it, itEnd);
        else
            (i % 2 == 0 ? a : b).insert((i % 2 == 0 ? a : b).end(), it, itEnd);                
        std::advance(it, cnt);
        i++;
    }

    generateJacobsthal(b.size() / cnt);
    _list.clear();
    _list = a;
    int j = 0;
    std::list<int> newList;
    for (size_t i = 0; i < b.size(); i += cnt){
        int right = 0;

        std::list<int>::iterator targetB = b.begin();
        std::advance(targetB, cnt * (_jacob[j] - 1));
        
        std::list<int>::iterator itbEnd = b.begin();
        if (cnt * (_jacob[j] - 1) + cnt > b.size())
            itbEnd = b.end();
        else
            std::advance(itbEnd, cnt * (_jacob[j] - 1) + cnt);

        int idxIt = 0;
        for (std::list<int>::iterator itList = _list.begin(); itList != _list.end(); itList++){
            if (idxIt % cnt == 0)
                newList.push_back(*itList);
            idxIt++;
        }

        if (*targetB != -1){
            if (_jacob[j] - 1 > static_cast<int>(a.size() / cnt))
                right = _jacob[j] - 1;
            else
                right = _jacob[j] - 1 + (i / cnt);
            int pos = binarySearch(newList, right, *targetB);
            std::list<int>::iterator posList = _list.begin();
            while (pos * cnt > _list.size())
                pos--;
            std::advance(posList, pos * cnt);
            _list.insert(posList, targetB, itbEnd);
        }
        newList.clear();
        j++;
    }
    a.clear();
    b.clear();
}