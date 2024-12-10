#include "PmergeMe.hpp"

int comparisonCount = 0;

PmergeMe::PmergeMe() : _size(0){}

PmergeMe::PmergeMe(int argc){
    if (argc % 2 == 0)
        _size = argc;
    else
        _size = argc - 1;
    _jacob = new int[_size];
}

PmergeMe::~PmergeMe() {}

void PmergeMe::printVector() {
    for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end(); ++it){
        //if (*it != -1)
            std::cout << *it << " "; 
    }
    if (std::is_sorted(_vec.begin(), _vec.end())){
        std::cout << "\033[32msuccess\033[0m" << std::endl;
    }
    else{
        std::cout << "\033[31mfailed\033[0m" << std::endl;
        //for (std::vector<int>::iterator it = _vec.begin(); it != _vec.end() - 1; ++it){
        //    if (*(it + 1) < *it)
        //        std::cout << *it << std::endl;
        //}
    }
    std::cout << std::endl;
}

void PmergeMe::printList() {
    for (std::list<int>::iterator it = _list.begin(); it != _list.end();){
        std::cout << *it << " ";
        ++it;
    }
    if (std::is_sorted(_list.begin(), _list.end())){
        std::cout << "\033[32msuccess\033[0m" << std::endl;
    }
    else{
        std::cout << "\033[31mfailed\033[0m" << std::endl;
        //for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it){
        //    std::list<int>::iterator next = ++it;
        //    if (*next < *it)
        //        std::cout << *it << std::endl;
        //}
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

//int PmergeMe::binarySearch(std::vector<int> &arr, size_t right, int target, int cnt){
//    size_t left = 0;

//    std::vector<int> newArr;
//    std::cout << "newArr:";
//    for (size_t i = 0; i + cnt <= arr.size(); i += cnt){
//        newArr.push_back(arr[i]);
//        std::cout << arr[i] << " ";
//    }
//    std::cout << std::endl;
//    std::cout << "target: " << target << " ";
//    while (left < right){
//        std::cout << "right: " << right << " left: " << left << " ";
//        size_t mid = left + (right - left) / 2;
//        std::cout << "mid: " << mid << std::endl;
//        if (mid >= newArr.size())
//            break ;
//        if (newArr[mid] < target)
//            left = mid + 1;
//        else
//            right = mid - 1;
//        if (right == 0)
//            break;
//    }
//    return left * cnt;
//}

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
            comparisonCount++;
            if (*it2 > *it){
                for (size_t i = 0; i < cnt; i++)
                    std::swap(*(it + i), *(it2 + i));
                std::cout << std::endl;
            }
        }
        mergeInsert(argc, cnt * 2);
        insert(cnt);
    }
    std::cout << "cnt :" << comparisonCount << std::endl;
}

bool customCompare(int a, int b) {
    comparisonCount++;
    return a < b;
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
            std::vector<int>::iterator pos = std::lower_bound(newArr.begin(), arrEnd, *targetB, customCompare);
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
    //std::cout << "cnt: " << cnt << std::endl;
    if (cnt * 2 > _size)
        return ;
    else{
        size_t idx = 0;
        size_t size = _list.size();
        //std::cout << "cnt: " << cnt << std::endl; 
        for (std::list<int>::iterator it = _list.begin(); it != _list.end();){
            std::list<int>::iterator nextIt = it;
            if (idx + cnt > size)
                break;
            std::advance(nextIt, cnt);
            if (nextIt != _list.end() && *nextIt > *it){
                if (std::distance(_list.begin(), nextIt) + cnt > _list.size())
                    break ;
                std::list<int>::iterator tmp_it = it;
                std::list<int>::iterator tmp_nextIt = nextIt;
                for (size_t i = 0; i < cnt && i + idx < size; i++){
                    //std::cout << "swap: " << *tmp_it << " " << *tmp_nextIt << std::endl;
                    std::swap(*tmp_it, *tmp_nextIt);
                    ++tmp_it;
                    ++tmp_nextIt;
                }
            }
            if (cnt * 2 + idx > size)
                break ; 
            idx += (cnt * 2);
            std::advance(it, cnt * 2);
        }
        //printList();
        mergeInsertList(argc, cnt * 2);
        insertList(cnt);
    }
}

std::list<int>::iterator PmergeMe::binarySearch(std::list<int> &arr, int right, int target){
    int left = 0;
    std::list<int>::iterator begin;
    
    while (left <= right){
        begin = arr.begin();
        int mid = left + (right - left) / 2;
        std::advance(begin, mid);
        if (*begin < target)
            left = mid + 1;
        else
            right = mid - 1;
    }
    while (*begin < target && begin != arr.end()){
        begin++;
    }
    return begin;
    //for (std::list<int>::iterator nextIt = begin; *nextIt < target && nextIt != arr.end();){
    //    left++;
    //    nextIt++;
    //}
    //std::cout << "left: " << left << std::endl;
    //return left;
}

void    PmergeMe::insertList(size_t cnt){
    std::list<int>      a, b;
    size_t              i = 0;;

    //std::cout << "cnt: " << cnt << std::endl;
    for (std::list<int>::iterator it = _list.begin(); it != _list.end();){
        std::list<int>::iterator itEnd = it;
        size_t remaining = std::distance(it, _list.end());
        if (cnt > remaining){
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

    //std::cout << "a: ";
    //for (std::list<int>::iterator it = a.begin(); it != a.end(); ++it){
    //    std::cout << *it << " ";
    //}
    //std::cout << std::endl << "b: ";
    //for (std::list<int>::iterator it = b.begin(); it != b.end(); ++it){
    //    std::cout << *it << " ";
    //}
    //std::cout << std::endl;

    generateJacobsthal(b.size() / cnt);
    _list.clear();
    _list = a;
    int j = 0;
    std::list<int> newList;
    for (size_t i = 0; i < b.size(); i += cnt){
        //int pos = 0;
        int right = 0;

        std::list<int>::iterator targetB = b.begin();
        std::advance(targetB, cnt * (_jacob[j] - 1));
        
        std::list<int>::iterator itbEnd = b.begin();
        if (std::distance(b.begin(), targetB) + cnt > b.size())
            itbEnd = b.end();
        else
            std::advance(itbEnd, std::distance(b.begin(), targetB) + cnt);

        for (std::list<int>::iterator itList = _list.begin(); itList != _list.end();){
            if (std::distance(_list.begin(), itList) % cnt == 0)
                newList.push_back(*itList);
            ++itList;
        }

        if (*targetB != -1){
            if (_jacob[j] - 1 > static_cast<int>(a.size() / cnt))
                right = _jacob[j] - 1;
            else
                right = _jacob[j] - 1 + (i / cnt);
            //std::cout << "right: " << right << std::endl;;
            std::list<int>::iterator pos = binarySearch(newList, right, *targetB);
            size_t distance = std::distance(newList.begin(), pos);
            //std::cout << "distance: " << distance << std::endl;;

            //std::cout << " pos: " << pos << std::endl;
            //std::cout << "before insert" << std::endl;
            //printList();
            //pos *= cnt;
            std::list<int>::iterator posList = _list.begin();
            while (distance * cnt > _list.size())
                distance--;
            std::advance(posList, distance * cnt);
            _list.insert(posList, targetB, itbEnd);
            //std::cout << "After insert" << std::endl;
            //printList();
            //std::cout << "targetB: " << *targetB << " itbEnd: " << *itbEnd << std::endl; 
        }
        //size_t idx = std::min(cnt * (_jacob[j] - 1), a.size() - 1);
        //std::advance(targetA, idx);
        //int pos = binarySearch(_list, *targetA, *targetB, cnt);
        //targetA = _list.begin();
        //std::advance(targetA, pos);
        //_list.insert(targetA, targetB, itbEnd);

        newList.clear();
        j++;
    }
    a.clear();
    b.clear();
}