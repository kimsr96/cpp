#include "Dog.hpp"

Dog::Dog(): Animal(), dogBrain(new Brain()){
    type = "Dog";
    std::cout << "Constructor Dog called" << std::endl;
}

Dog::~Dog(){
    delete dogBrain;
    std::cout << "Destructor Dog called" << std::endl;
}

Dog::Dog(const Dog &copy): Animal(copy){
}

Dog& Dog::operator=(const Dog& copy){
    if (this != &copy)
    {
        type = copy.type;
        if (dogBrain)
        {
            delete dogBrain;
            dogBrain = new Brain(*copy.dogBrain);
        }
    }
    return *this;
}

void Dog::makeSound() const{
    std::cout << "Bark Bark" << std::endl;
}

std::string Dog::getBrainIdeas(int i) const{
    return dogBrain->getIdeas(i);
}

void    Dog::setBrainIdeas(std::string name){
    dogBrain->setIdeas(name);
}