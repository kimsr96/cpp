#include "Dog.hpp"

Dog::Dog(): Animal(){
    type = "Dog";
    std::cout << "Constructor Dog called" << std::endl;
}

Dog::~Dog(){
    std::cout << "Destructor Dog called" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy){
}

Dog& Dog::operator=(const Dog& copy){
    if (this != &copy)
        type = copy.type;
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Bark Bark" << std::endl;
}