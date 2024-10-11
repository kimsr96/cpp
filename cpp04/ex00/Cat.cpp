#include "Cat.hpp"

Cat::Cat(): Animal(){
    type = "Cat";
    std::cout << "Constructor Cat called" << std::endl;
}

Cat::~Cat(){
    std::cout << "Destructor Cat called" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy){
}

Cat& Cat::operator=(const Cat& copy){
    if (this != &copy)
        type = copy.type;
    return *this;
}

void Cat::makeSound(void) const{
    std::cout << "Nya onnng" << std::endl;
}