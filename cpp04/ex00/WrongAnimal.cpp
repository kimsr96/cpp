#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(): type("WrongAnimal"){
    std::cout << "Constructor WrongWrongAnimal called" << std::endl;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "Destructor WrongAnimal called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &copy): type(copy.type){
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& copy){
    if (this != &copy)
        type = copy.type;
    return *this;
}

void WrongAnimal::makeSound(void) const{
    std::cout << "WrongAnimal making sound" << std::endl;
}

const std::string& WrongAnimal::getType(void) const{
    return type;
}