template <typename T>
MutantStack<T>::MutantStack() : std::stack<T, std::deque<T> >(){
}

template <typename T>
MutantStack<T>::~MutantStack(){}

template <typename T>
MutantStack<T>::MutantStack(const MutantStack &copy) : std::stack<T, std::deque<T> >(copy){
}

template <typename T>
MutantStack<T>& MutantStack<T>::operator=(const MutantStack &copy){
    if (this != &copy)
        std::stack<T, std::deque<T> >::operator=(copy);  
    return *this;
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::begin(){
    return this->c.begin();
}

template <typename T>
typename std::deque<T>::reverse_iterator MutantStack<T>::rbegin(){
    return this->c.rbegin();
}

template <typename T>
typename std::deque<T>::iterator MutantStack<T>::end(){
    return this->c.end();
}

template <typename T>
typename std::deque<T>::reverse_iterator MutantStack<T>::rend(){
    return this->c.rend();
}
