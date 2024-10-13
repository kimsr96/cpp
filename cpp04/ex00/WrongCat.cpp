#include "WrongCat.hpp"

WrongCat::WrongCat(): WrongAnimal(){
    type = "WrongCat";
    std::cout << "Constructor WrongCat called" << std::endl;
}

WrongCat::~WrongCat(){
    std::cout << "Destructor WrongCat called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &copy): WrongAnimal(copy){
}

WrongCat& WrongCat::operator=(const WrongCat& copy){
    if (this != &copy)
        type = copy.type;
    return *this;
}

void WrongCat::makeSound(void) const{
    std::cout << "Nya onnng" << std::endl;
}