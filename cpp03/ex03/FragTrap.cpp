#include "FragTrap.hpp"

FragTrap::FragTrap(){
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "Constructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name){
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "Constructor FragTrap with name called" << std::endl;
}

FragTrap::~FragTrap(){
    std::cout << "Destructor FragTrap called" << std::endl;
}

FragTrap::FragTrap(const FragTrap &copy) : ClapTrap(copy){
    std::cout << "Copy constructor FragTrap called" << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &copy){
    if (this != &copy){
        ClapTrap::operator=(copy);
    }
    return *this;
}

void FragTrap::highFivesGuys(){
    std::cout << _name << " positive highFive !" << std::endl; 
}

