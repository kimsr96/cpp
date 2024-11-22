#include "RPN.hpp"

void    RPN::result(){
    if (_stack.empty())
        throw NotEnoughElement();
    std::cout << _stack.top() << std::endl;
}

void    RPN::calculateStack(char oper){
    if (_stack.size() < 2)
        throw NotEnoughElement();
    int b = _stack.top();
    _stack.pop();
    int a = _stack.top();
    _stack.pop();

    if (oper == '+')
        _stack.push(a + b);
    else if (oper == '-')
        _stack.push(a - b);
    else if (oper == '*')
        _stack.push(a * b);
    else if (oper == '/'){
        if (b == 0)
             throw DivideZeroException();
        _stack.push(a / b);
    }
}

void RPN::splitData(char *argv){
    int     i = 0;

    while (argv[i]){
        if (argv[i] == ' '){
            i++;
            continue;
        }
        else if (argv[i] == '+' || argv[i] == '-' || argv[i] == '*' || argv[i] == '/')
            calculateStack(argv[i]);
        else if (argv[i] == '(' || argv[i] == ')' || argv[i] == '.')
            throw ErrorException();
        else
            _stack.push(argv[i] - '0');
        i++;
    }
}

const char* RPN::NotEnoughElement::what() const throw(){
    return "Error: not enough Element";
}

const char* RPN::DivideZeroException::what() const throw(){
    return "Error: can not divide by zero";
}

const char* RPN::ErrorException::what() const throw(){
    return "Error";
}