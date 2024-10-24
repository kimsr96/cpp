#include "Animal.hpp"

Animal::Animal(): type("Animal"){
    std::cout << "Constructor Animal called" << std::endl;
}

Animal::~Animal(){
    std::cout << "Destructor Animal called" << std::endl;
}

Animal::Animal(const Animal &copy): type(copy.type){
}

Animal& Animal::operator=(const Animal& copy){
    if (this != &copy)
        type = copy.type;
    return *this;
}

void Animal::makeSound(void) const{
    std::cout << "Animal making sound" << std::endl;
}

const std::string& Animal::getType(void) const{
    return type;
}