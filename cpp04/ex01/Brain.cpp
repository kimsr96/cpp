#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Constructor Brain called" << std::endl;
    for (int i = 0; i < 100; i++){
        ideas[i] = "idea" + std::to_string(i);
    }
}

Brain::~Brain(){
    std::cout << "Destructor Brain called" << std::endl;
}

Brain::Brain(const Brain &copy){
    for (int i = 0; i < 100; i++){
        ideas[i] = copy.ideas[i];
    }
}

Brain& Brain::operator=(const Brain &copy){
    if (this != &copy){
        for (int i = 0; i < 100; i++){
            ideas[i] = copy.ideas[i];
        }
    }
    return *this;
}

std::string Brain::getIdeas(int i) const{
    return ideas[i];
}

void    Brain::setIdeas(std::string &name){
    for (int i = 0; i < 100; i++){
        ideas[i] = name + ideas[i];
    }
}

