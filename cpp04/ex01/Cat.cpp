#include "Cat.hpp"

Cat::Cat(): Animal(), catBrain(new Brain()){
    type = "Cat";
    std::cout << "Constructor Cat called" << std::endl;
}

Cat::~Cat(){
    delete catBrain;
    std::cout << "Destructor Cat called" << std::endl;
}

Cat::Cat(const Cat &copy): Animal(copy){
    catBrain = new Brain(*copy.catBrain);
}

Cat& Cat::operator=(const Cat& copy){
    if (this != &copy)
    {
        type = copy.type;
        if (catBrain)
            delete catBrain;
        catBrain = new Brain(*copy.catBrain);
    }
    return *this;
}

void Cat::makeSound(void) const{
    std::cout << "Nya onnng" << std::endl;
}

std::string Cat::getBrainIdeas(int i) const{
    return catBrain->getIdeas(i);
}

void    Cat::setBrainIdeas(std::string name){
    catBrain->setIdeas(name);
}